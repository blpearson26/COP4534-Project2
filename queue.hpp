#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "customer.hpp"

class Queue {
private:
	Customer *head;
	Customer *tail;
	bool isEmpty;
	int size;

public:
	Queue();
	void PushBack(float data);
	Customer Pop();
	bool IsEmpty();
	int GetSize();

};

#endif