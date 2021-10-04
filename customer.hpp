#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include <iostream>
#include <vector>
using namespace std;

class Customer {

private:
	float arrivalTime;
	float startOfServiceTime; //currentWaitTime = startOfServiceTime - arrivalTime
	float departureTime; //serviceTime = depatureTime - startOfServiceTime
	Customer * nextCust;

public:
	Customer(int arrivalTime);
	void SetDepartureTime(float intervalTime);
	int GetArrivalTime();
};


#endif