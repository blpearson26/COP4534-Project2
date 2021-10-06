#ifndef EVENT_HPP
#define EVENT_HPP
#include "customer.hpp"

class Event {
private:
	bool isDeparture;
	float time;
	Customer cust; 

public:
	Event();
	Event(bool isDeparture, float time, Customer cust);
	bool IsDeparture();
	void SetTime(float time);
	float GetTime();
	Customer GetCust();


};

#endif