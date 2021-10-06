#include "event.hpp"

Event::Event()
{

}

Event::Event(bool isDeparture, float time, Customer cust)
{
	this->isDeparture = isDeparture;
	this->time = time;
	this->cust = cust;

}
bool Event::IsDeparture()
{
	return this->isDeparture;
}
void Event::SetTime(float time)
{
	this->time = time;
}
float Event::GetTime()
{
	return this->time;
}
Customer Event::GetCust()
{
	return this->cust;
}