#include "heap.hpp"

Heap::Heap(int maxSize)
{
	this->size = 0;
	this->maxSize = maxSize;
	this->heapArray = new Event[maxSize];

}
int Heap::GetParent(int i)
{
	return (i-1)/2;
}
int Heap::GetLeftChild(int i)
{
	return (2*i+1);
}
int Heap::GetRightChild(int i)
{
	return (2*i+2);
}
Event Heap::Peek()
{ 
	return heapArray[0];
}
void Heap::Insert(Event i)
{
	if(size == maxSize)
	{
		cout << "ERROR: Heap is Full could not insertKey" << endl;
		return;
	}
	++size;
	int index = size - 1;
	heapArray[index] = i;

	while(index != 0 && heapArray[GetParent(index)].GetTime() > heapArray[index].GetTime())
	{
		swap(&heapArray[index], &heapArray[GetParent(index)]);
		index = GetParent(index);
	}
}
void Heap::swap(Event *x, Event *y)
{
	Event temp = *x;
	*x = *y;
	*y = temp;
}

Event Heap::Pop()
{
	if(size <= 0)
		exit(1);
	if(size == 1)
	{
		--size;
		return heapArray[0];
	}

	Event root = heapArray[0];
	heapArray[0] = heapArray[size - 1];
	--size;
	Heapify(0);

	return root;
}
void Heap::Heapify(int i)
{
	int left = GetLeftChild(i);
	int right = GetRightChild(i);
	int min = i;

	if(left < size && heapArray[left].GetTime() < heapArray[right].GetTime())
		min = left;

	if(right < size && heapArray[right].GetTime() < heapArray[min].GetTime())
		min = right;

	if(i != min)
	{
		swap(&heapArray[i], &heapArray[min]);
		Heapify(min);
	}
}
void Heap::PrintHeap()
{
	for(int i = 0; i < size; ++i)
	{
		cout << "Heap Index " << i << ": " << heapArray[i].GetTime() << endl;
	}
}
bool Heap::IsEmpty()
{
	if(this->size <= 0)
		return true;

	else
		return false;
}