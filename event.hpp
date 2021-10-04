#ifndef EVENT_HPP
#define EVENT_HPP

class Event {
private:
	bool isDeparture;
	float time; 

public:
	Event();
	Event(bool isDeparture, float time);
	bool IsDeparture();
	void SetTime(float time);
	float GetTime();


};

#endif