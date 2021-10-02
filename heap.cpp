#include "heap.hpp"

Heap::Heap(int maxSize)
{
	this->size = 0;
	this->maxSize = maxSize;
	this->heapArray = new float[maxSize];

}
int Heap::GetParent(int i)
{
	return (i-1)/2;
}
void Heap::insertKey(float i)
{
	if(size == maxSize)
	{
		cout << "ERROR: Heap is Full could not insertKey" << endl;
		return;
	}
	++size;
	int index = size - 1;
	heapArray[index] = i;

	while(index != 0 && heapArray[GetParent(index)] > heapArray[index])
	{
		swap(heapArray[index], heapArray[GetParent(index)]);
		index = GetParent(index);
	}
}
void Heap::swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}
/*float Heap::extractMin()
{
	if(size <= 0)
		return INT_MAX;
	if(size == 1)
	{
		--size;
		return heapArray[0];
	}

	float root = heapArray[0];
	heapArray[0]
}*/