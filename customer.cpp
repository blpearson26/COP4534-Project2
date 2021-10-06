#include "customer.hpp"

Customer::Customer()
{
	this->arrivalTime = -1;
}

Customer::Customer(float arrivalTime)
{
	this->arrivalTime = arrivalTime;

	//startOfServiceTime = nullptr;
	//departureTime = nullptr;
}

/*void Customer::SetDepartureTime(float intervalTime)
{
	this->departureTime = this->startOfServiceTime + intervalTime;
}
float Customer::GetArrivalTime()
{
	return this->arrivalTime;
}
Customer* Customer::GetNext()
{
	return this->nextCust;
}
void Customer::SetNext(Customer *newCust)
{
	this->nextCust = newCust;
}
void Customer::PrintList()
{
	Customer* curNode = this->head;
	while(curNode != NULL)
	{
		cout << curNode->arrivalTime << endl;
		curNode = curNode->nextCust;
	}
}
void Customer::Insert(float data)
{
	Customer *curNode = new Customer;
	curNode->arrivalTime = data;
	curNode->nextCust = NULL;
	if(head == NULL)
	{
		head = curNode;
	}
	else
	{
		while(curNode != NULL)
		//curNode->nextCust = head;
		//head = curNode;
	}
}*/