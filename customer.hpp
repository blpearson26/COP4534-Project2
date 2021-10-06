#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include <iostream>
#include <vector>
using namespace std;

class Customer {

public:
	Customer();
	Customer(float arrivalTime);
	float arrivalTime;
	float startOfServiceTime; //currentWaitTime = startOfServiceTime - arrivalTime
	float departureTime; //serviceTime = depatureTime - startOfServiceTime
	Customer * nextCust;
	/*
	void SetDepartureTime(float intervalTime);
	float GetArrivalTime();
	Customer* GetNext();
	void SetNext(Customer *newCust);
	void PrintList();
	void Insert(float data);*/
};


#endif