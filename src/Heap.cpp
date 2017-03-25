//============================================================================
// Name        : Heap.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
using namespace std;

void swap(int *x, int *y);

class MaxHeap{
	int *heapArr;
	int capacity;
	int heapSize;

public:
	//Constructor
	MaxHeap(int capacity);

	//Heapify subtree with given index
	void MaxHeapify(int);

	int parent(int i)	{	return (i-1)/2;	}
	int left(int i)		{	return 2*i+1; 	}
	int right(int i)	{	return 2*i+2; 	}

	//extract the Minimum ( root )
	int extractMax();

	void increaseKey(int i, int new_val);

	//return the Minimum ( root )
	int getMax(){ return heapArr[0]; }

	void deleteKey(int i);

	void insertKey(int k);

};

MaxHeap::MaxHeap(int cap){			// Constructor to build a heap with given size
	heapSize=0;
	capacity=cap;
	heapArr=new int[cap];
}


void MaxHeap::insertKey(int key){	//Insert a new key in the heap
	if(heapSize==capacity){
		cout << "Error, can't insert. Heap is Full !!";
		return;
	}

	int i=heapSize++;
	heapArr[i]=key;					// inserts the key at the end of the heap

	while(i!=0 && heapArr[parent(i)] < heapArr[i]){	// Fixing the heap
		swap(&heapArr[i], &heapArr[parent(i)]);
		i=parent(i);
	}
}

void MaxHeap::increaseKey(int i, int newValue){		// Decrease the value of element which have index i
	heapArr[i]=newValue;
	while(i!=0 && heapArr[parent(i)] < heapArr[i]){
		swap(&heapArr[i], &heapArr[parent(i)]);
		i=parent(i);
	}
}

int MaxHeap::extractMax(){			// remove the smallest element ( root ) from the heap.
	if(heapSize <= 0)
		return INT_MIN;
//	if(heapSize==1){
//		heapSize--;
//		return heapArr[0];
//	}

	// stores the minimum value, and remove it from the heap, then return it.
	int root=heapArr[0];
	heapArr[0]=heapArr[heapSize-1];
	heapSize--;
	MaxHeapify(0);

	return root;
}


void MaxHeap::deleteKey(int i){		// Delete a key at index i
	increaseKey(i, INT_MAX);
	extractMax();
}

void MaxHeap::MaxHeapify(int i){	// Heapify a sub tree with given index i
	int l=left(i);
	int r=right(i);
	int biggest=i;

	if(l < heapSize && heapArr[l] > heapArr[i])
		biggest=l;
	if(r < heapSize && heapArr[r] > heapArr[biggest])
		biggest=r;
	if(biggest != i){
		swap(&heapArr[i], &heapArr[biggest]);
		MaxHeapify(biggest);
	}
}


// function to swap two elements
void swap(int *x, int *y){
	int temp = *x;
	*x= *y;
	*y= temp;
}


int main() {
	MaxHeap heap(11);

//	heap.insertKey(3);
//    heap.insertKey(2);
//    heap.deleteKey(1);
//    heap.insertKey(15);
//    heap.insertKey(5);
//    heap.insertKey(4);
//    heap.insertKey(45);
//    cout << heap.extractMax() << " ";
//    cout << heap.getMax() <<	 " ";
//    heap.increaseKey(2, 1);
//    cout << heap.getMax();

	heap.insertKey(35);
	heap.insertKey(33);
	heap.insertKey(42);
	heap.insertKey(10);
	heap.insertKey(14);
	heap.insertKey(19);
	heap.insertKey(27);
	heap.insertKey(44);
	heap.insertKey(26);
	heap.insertKey(31);

	heap.deleteKey(0);
	heap.deleteKey(0);


	for(int i=0; i<8; i++){
		cout << heap.extractMax() << " ";

	}


	return 0;
}
