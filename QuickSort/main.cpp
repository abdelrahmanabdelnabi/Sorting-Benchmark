/*
 * main.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: abdou
 */

#include <iostream>
//#include "quicksort.cpp"

using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int array[], int p, int r) {
	int x = array[r];
	int i = p - 1;

	for(int j = p; j < r; j++) {
		if(array[j] <= x) {
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i+1], &array[r]);
	return i + 1;
}

void quickSort(int array[], int low, int high) {
	if(low < high) {
		int q = partition(array, low, high);
		quickSort(array, low, q - 1);
		quickSort(array, q + 1, high);
	}

}

void sort(int array[]) {
	quickSort(array, 0, 10);
}



int main(void) {
	int testArray[] = {90, 44, 6, 72, 3, 1, 23, 15, 80, 0};

	sort(testArray);

	for(int i = 0; i < sizeof(testArray)/sizeof(int); i++) {
		cout << testArray[i] << " ";
	}

}
