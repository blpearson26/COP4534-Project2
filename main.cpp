#include <iostream>
#include <random>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "heap.hpp"
#include "customer.hpp"
#include "event.hpp"
#include "queue.hpp"
#include "filehandler.hpp"
using namespace std;

int M, mu, lambda, maxServers, total = 0;
int waitCount, idleTimes = 0;
float totalWaitTime, totalServiceTime = 0;
int pqSize = 200;

float GetNextRandomInterval(int avg)
{
	const float MAX = 1.0;
	float f = ((float)rand()/(float)(RAND_MAX) * 1.0);
	float intervalTime = -1 * (1.0/avg) * log(f);

	return intervalTime;
}
float ProcessStatistics(Customer cust)
{

	float currentWaitTime = cust.startOfServiceTime - cust.arrivalTime;
	float serviceTime = cust.departureTime - cust.startOfServiceTime;

	if(currentWaitTime > 0)	
		waitCount += 1;

	totalWaitTime = totalWaitTime + currentWaitTime;
	totalServiceTime = totalServiceTime + serviceTime;

	if(M == maxServers)
		idleTimes = idleTimes + 1;
}
void ProcessNextEvent(Heap *h, Queue *q)
{
	Event e = h->Pop();

	if(!e.IsDeparture())
	{
		if(M > 0)
		{
			--M;
			Customer cust = e.GetCust();
			cust.startOfServiceTime = cust.arrivalTime;
			float interval = GetNextRandomInterval(mu);
			cust.departureTime = cust.startOfServiceTime + interval;
			Event newEvent(true, cust.departureTime, cust);
			h->Insert(newEvent);
		}
		else
			q->PushBack(e.GetTime());
	}
	else
	{
		++M;
		ProcessStatistics(e.GetCust());
		
		if(q->IsEmpty() == false)
		{
			Customer newCust = q->Pop();
			newCust.startOfServiceTime = e.GetTime();
			float interval = GetNextRandomInterval(mu);
			newCust.departureTime = newCust.startOfServiceTime + interval;
			Event newEvent(true, newCust.departureTime, newCust);
			h->Insert(newEvent);
			--M;
		}
	}
}
void AddToHeap(Heap *h, float *time)
{
	*time += GetNextRandomInterval(lambda);
	Customer newCust(*time);
	Event a(false, newCust.arrivalTime, newCust);
	h->Insert(a);
	--total;
}
void RunSim(Heap *h, float *time, Queue *q, string filename)
{
	cout << "-------------------------------------------" << endl;
	cout << "| Running Simulation For Following Values |" << endl;
	cout << "|         Pulled from File " << filename << "      |" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "|    LAMBDA VAL: " << lambda << "                        |" << endl;
	cout << "|    MU VAL: " << mu << "                            |" << endl;
	cout << "|    M VAL: " << M << "                             |" << endl;
	cout << "|    Total Events: " << total << "                   |" << endl;
	cout << "-------------------------------------------" << endl;


	for(int i = 0; i < pqSize; ++i)
	{
		AddToHeap(h, time);
	}

	while(!h->IsEmpty())
	{
		ProcessNextEvent(h, q);

		if(total != 0 && h->GetSize() <= maxServers + 1)
			AddToHeap(h, time);
	}

	//cout << "TOTAL: " << total << endl;
	cout << "  Results: " << endl;
	cout << "  ----------" << endl;
	cout << "  Customers that had to wait: " << waitCount << endl;
	cout << "  Total Wait Time: " << totalWaitTime << endl;
	cout << "  Total Service Time: " << totalServiceTime << endl;
	cout << "  Times that no customers were being serviced: " << idleTimes << endl << endl;
}

int main()
{
	srand((unsigned int)time(NULL));

	string filename = "test1.txt";
	FileHandler *fh = new FileHandler(filename, &lambda, &mu, &M, &total);
	maxServers = M;
	Heap *h = new Heap(pqSize);
	Queue *q = new Queue();
	float time = 0.0;

	RunSim(h, &time, q, filename);

	filename = "test2.txt";

	fh = new FileHandler(filename, &lambda, &mu, &M, &total);
	maxServers = M;

	RunSim(h, &time, q, filename);




	return 0;
}