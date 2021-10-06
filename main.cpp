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

int M = 0;
int mu = 0;
int lambda = 0;
int maxServers = 0;
int total = 0;
int waitCount = 0;
float totalWaitTime = 0.0;
float totalServiceTime = 0.0;
int idleTimes = 0;



float GetNextRandomInterval(int avg){

	const float MAX = 1.0;
	float f = ((float)rand()/(float)(RAND_MAX) * 1.0);
	float intervalTime = -1 * (1.0/avg) * log(f);

	return intervalTime;
	
}
//float ProcessStatistics(Customer cust, int *waitCount, int *M, float *totalWaitTime, float *totalServiceTime, int *idleTimes)
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
//void ProcessNextEvent(Heap *h, int *M, int mu, Queue *q, int *waitCount, float *totalWaitTime, float *totalServiceTime, int *idleTimes)
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
		//	cout << "\n*** YES SERVERS AVAILABLE. DEPARTURE ADDED ***\n" << endl;
		}
		else
			{
				//cout <<"TIME PUSHED TO QUEUE: " << e.GetTime();
				q->PushBack(e.GetTime());
				//cout << "\n*** NO SERVERS AVAILABLE. ADDED TO QUEUE ***\n" << endl;
			}
	}
	else
	{
		++M;
		//cout << "\n*** DEPARTURE EVENT:" << endl;
		ProcessStatistics(e.GetCust());
		
		if(q->IsEmpty() == false)
		{
			//cout << "\n**************************************************" << endl;
			//cout << "\n*** DEPARTURE && CUSTOMER FORM QUEUE ADDED ***\n" << endl;
			//cout << "\n**************************************************\n" << endl;
			Customer newCust = q->Pop();
			//cout << "ARRIVAL TIME OF POPPED QUEUE ELEMENT: " << newCust.arrivalTime << endl;
			newCust.startOfServiceTime = e.GetTime();
			float interval = GetNextRandomInterval(mu);
			newCust.departureTime = newCust.startOfServiceTime + interval;
			Event newEvent(true, newCust.departureTime, newCust);
			h->Insert(newEvent);
			--M;
		}
		//else
		//	cout << "NO CUSTOMERS IN QUEUE" << endl;

	}
}

int main()
{
	srand((unsigned int)time(NULL));
	//int lambda = 2; //avg no of arrivals
	//int mu = 3;		//avg customers serviced per time unit
	//int M = 2;		//number of servers
	//int total = 5000; //total events to simulate
	int pqSize = 200;
	/*int waitCount = 0;
	float totalWaitTime = 0.0;
	float totalServiceTime = 0.0;
	int idleTimes = 0;*/
	FileHandler *fh = new FileHandler("test1.txt", &lambda, &mu, &M, &total);
	maxServers = M;
	delete fh;
	cout << "LAMBDA VAL: " << lambda << endl;
	cout << "MU VAL: " << mu << endl;
	cout << "M VAL: " << M << endl;
	cout << "Total VAL: " << total << endl;


	Heap *h = new Heap(pqSize);
	Queue *q = new Queue();
	float time = 0;

	for(int i = 0; i < pqSize; ++i)
	{
		time += GetNextRandomInterval(lambda);
		Customer newCust(time);
		//cout << time << endl;
		Event a(false, newCust.arrivalTime, newCust);
		h->Insert(a);
		--total;
	}
	//cout << "TOTAL: " << total << endl;

	while(!h->IsEmpty())
	{
		//ProcessNextEvent(h, &M, mu, q, &waitCount, &totalWaitTime, &totalServiceTime, &idleTimes);
		ProcessNextEvent(h, q);
//cout << "AVAILABLE SERVERS: " << M << endl;

		if(total != 0 && h->GetSize() <= maxServers + 1)
		{
			time += GetNextRandomInterval(lambda);
			Customer newCust(time);
			Event newEvent(false, newCust.arrivalTime, newCust);
			h->Insert(newEvent);
			--total;
		}

	}
	cout << "TOTAL: " << total << endl;
	cout << "WAIT COUNT: " << waitCount << endl;
	cout << "WAIT TIME: " << totalWaitTime << endl;
	cout << "Service Time: " << totalServiceTime << endl;
	cout << "Idle Times: " << idleTimes << endl;

	fh = new FileHandler("test2.txt", &lambda, &mu, &M, &total);
	maxServers = M;
	cout << "LAMBDA VAL: " << lambda << endl;
	cout << "MU VAL: " << mu << endl;
	cout << "M VAL: " << M << endl;
	cout << "Total VAL: " << total << endl;
		//h->PrintHeap();
		//cout << "AVAILABLE SERVERS: " << M << endl;



	return 0;
}