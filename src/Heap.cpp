//============================================================================
// Name        : Heap.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
#include <stdlib.h>

using namespace std;

void swap(int *x, int *y);

class MaxHeap{

public:

	int *heapArr;
	int capacity;
	int heapSize;

	//Constructor
	MaxHeap(int capacity);

	//Heapify subtree with given index
	void MaxHeapify(int, int);

	int parent(int i)	{	return (i-1)/2;	}
	int left(int i)		{	return 2*i+1; 	}
	int right(int i)	{	return 2*i+2; 	}

	//extract the Maximum ( root )
	int extractMax();

	void increaseKey(int i, int new_val);

	//return the Maximum ( root )
	int getMax(){ return heapArr[0]; }

	void deleteKey(int i);

	void insertKey(int k);

	void heapSort();

	void printHeapArray();

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

void MaxHeap::increaseKey(int i, int newValue){		// Increases the value of element which have index i
	heapArr[i]=newValue;
	while(i!=0 && heapArr[parent(i)] < heapArr[i]){
		swap(&heapArr[i], &heapArr[parent(i)]);
		i=parent(i);
	}
}

int MaxHeap::extractMax(){			// remove the biggest element ( root ) from the heap.
	if(heapSize <= 0)
		return INT_MIN;
//	if(heapSize==1){
//		heapSize--;
//		return heapArr[0];
//	}

	// stores the maximum value, and remove it from the heap, then return it.
	int root=heapArr[0];
	heapArr[0]=heapArr[heapSize-1];
	heapSize--;
	MaxHeapify(0, heapSize);

	return root;
}


void MaxHeap::deleteKey(int i){		// Delete a key at index i
	increaseKey(i, INT_MAX);
	extractMax();
}

void MaxHeap::MaxHeapify(int i, int n){	// Heapify a sub tree with given index i, n is the size of the heap

	int l=left(i);
	int r=right(i);
	int biggest=i;

	if(l < n && heapArr[l] > heapArr[i])
		biggest=l;
	if(r < n && heapArr[r] > heapArr[biggest])
		biggest=r;
	if(biggest != i){
		swap(&heapArr[i], &heapArr[biggest]);
		MaxHeapify(biggest, n);
	}
}


// function to swap two elements
void swap(int *x, int *y){
	int temp = *x;
	*x= *y;
	*y= temp;
}


void MaxHeap::heapSort(){

	for(int i=heapSize-1; i>=0; i--){
		swap(heapArr[0], heapArr[i]);
		MaxHeapify(0, i);
	}
}

void MaxHeap::printHeapArray(){
	for(int i=0; i<heapSize; i++){
		cout << heapArr[i] << " ";
	}
	cout << endl;
}


int main() {

	MaxHeap heap(1000);

	for(int i=0; i<100; i++){
		heap.insertKey(rand()%1000);
	}

	heap.printHeapArray();

	heap.heapSort();

	heap.printHeapArray();

	return 0;
}
