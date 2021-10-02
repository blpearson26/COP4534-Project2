#ifndef HEAP_HPP
#define HEAP_HPP
#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
	float *heapArray;
	int maxSize;
	int size;

public:
	Heap(int maxSize);
	void Heapify(int i);
	int GetParent(int i);
	int left(int i){return (2*i+1);}
	int right(int i){return (2*i+2);}
	int extractMin();
	void decreaseKey(int i, int new_val);
	float GetMin(){ return heapArray[0];}
	void deleteKey(int i);
	void insertKey(float i);
	void swap(int x, int y);
};

#endif