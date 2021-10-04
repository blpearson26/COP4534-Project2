#include "customer.hpp"

Customer::Customer(int arrivalTime)
{
	this->arrivalTime = arrivalTime;
	//startOfServiceTime = nullptr;
	//departureTime = nullptr;
}
void Customer::SetDepartureTime(float intervalTime)
{
	this->departureTime = this->startOfServiceTime + intervalTime;
}