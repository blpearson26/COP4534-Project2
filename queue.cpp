#include "queue.hpp"

Queue::Queue()
{
	head = NULL;
	tail = NULL;
	size = 0;
}
void Queue::PushBack(float data)
{
	isEmpty = false;
	Customer *newNode = new Customer(data);

	if(tail == NULL)
	{
		tail = head = newNode;
		return;
	}

	tail->nextCust = newNode;
	tail = newNode;
	++size;
}

Customer Queue::Pop()
{
	if(head == NULL)
		tail = NULL;

	Customer *temp = head;
	head = head->nextCust;

	--size;

	
		
	return *temp;
}
bool Queue::IsEmpty()
{
	if(this->size > 0)
		return false;

	else
		return true;
}
int Queue::GetSize()
{
	return this->size;
}