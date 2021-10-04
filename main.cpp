#include <iostream>
#include <random>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "heap.hpp"
#include "customer.hpp"
#include "event.hpp"
using namespace std;

float GetNextRandomInterval(int avg){

	const float MAX = 1.0;
	float f = ((float)rand()/(float)(RAND_MAX) * 1.0);
	float intervalTime = -1 * (1.0/avg) * log(f);

	return intervalTime;
	
}

int main()
{
	srand((unsigned int)time(NULL));
	int lambda = 2; //avg no of arrivals
	int mu = 3;		//avg customers serviced per time unit
	int M = 2;		//number of servers
	int total = 5000; //total events to simulate
	int pqSize = 200;

	Heap *h = new Heap(pqSize);
	float time = 0;

	for(int i = 0; i < pqSize; ++i)
	{
		time += GetNextRandomInterval(lambda);
		Event a(false, time);
		h->Insert(a);
	}
	while(!h->IsEmpty())
	{
		//ProcessNextEvent(h->)
	}
	//h->PrintHeap();


	//cout << GetNextRandomInterval(mu) << endl;


	/*Event a(false, GetNextRandomInterval(lambda));
	Event b(false, GetNextRandomInterval(lambda));
	Event c(false, GetNextRandomInterval(lambda));
	Event d(false, GetNextRandomInterval(lambda));

	h->insertKey(a);
	h->insertKey(b);
	h->insertKey(c);
	h->insertKey(d);

	h->PrintHeap();

	cout << "\nAT HEAP ROOT: " << h->Pop().GetTime() << endl << endl;
	h->PrintHeap();

	/*for(int i = 0; i < pqSize; ++i)
	{
		Customer *c = new Customer(GetNextRandomInterval(lambda));
	}

	/*h->insertKey(3);
	h->insertKey(6);
	h->insertKey(5);
	h->insertKey(8);
	h->insertKey(7);
	h->insertKey(2);
	h->insertKey(9);
	h->insertKey(1);
	h->PrintHeap();
	cout << "AT HEAP ROOT: " << h->extractMin() << endl;
	h->PrintHeap();*/



	return 0;
}