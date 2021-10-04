#ifndef HEAP_HPP
#define HEAP_HPP
#include <iostream>
#include <vector>
#include "event.hpp"
using namespace std;

class Heap {
private:
	Event* heapArray;
	int maxSize;
	int size;

public:
	Heap(int maxSize);
	void Heapify(int i);
	int GetParent(int i);
	int GetLeftChild(int i);
	int GetRightChild(int i);
	Event Pop();
	//void decreaseKey(int i, int new_val);
	Event Peek();
	//void deleteKey(int i);
	void Insert(Event i);
	void PrintHeap();
	void swap(Event *x, Event *y);
	bool IsEmpty();
};

#endif