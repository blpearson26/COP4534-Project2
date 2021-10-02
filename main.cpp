#include <iostream>
#include <random>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "heap.hpp"
using namespace std;

float GetNextRandomInterval(int avg){
	srand((unsigned int)time(NULL));
	const float MAX = 1.0;
	float f = ((float)rand()/(float)(RAND_MAX) * MAX);
	float intervalTime = -1 * (MAX/avg) * log(f);

	return intervalTime;
	

}

int main()
{
	int lambda = 2; //avg no of arrivals
	int mu = 3;		//avg customers serviced per time unit
	int M = 2;		//number of servers
	int total = 5000; //total events to simulate

	cout << "Hello World!" << endl;
	cout << GetNextRandomInterval(lambda) << endl;

	/*Heap *h = new Heap(200);
	h->insertKey(GetNextRandomInterval(lambda));
	h->insertKey(GetNextRandomInterval(lambda));
	cout << "AT HEAP ROOT: " << h->GetMin() << endl;*/



	return 0;
}