/*
 * quicksort.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: Abdelrahman Abdelnabi
 */

#include <iostream>

void sort(int array[]);
void quickSort(int array[], int low, int high);
int partition(int array[], int p, int r);
int swap(int* a, int* b);

void sort(int array[]) {
	quickSort(array, 0, (sizeof(array)/sizeof(int)));
}


void quickSort(int array[], int low, int high) {
	if(low < high) {
		int q = partition(array, low, high);
		quickSort(array, low, q - 1);
		quickSort(array, q + 1, high);
	}

}


int partition(int array[], int p, int r) {
	int x = array[r];
	int i = p - 1;

	for(int j = p; j < r-1; j++) {
		if(array[j] <= x) {
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i+1], &array[r]);
	return i + 1;
}


void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
