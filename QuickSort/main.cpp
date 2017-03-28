/*
 * main.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: abdou
 */

#include <iostream>
//#include "quicksort.cpp"

#include <fstream>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int array[], int p, int r) {
	int x = array[r];
	int i = p - 1;

	for (int j = p; j < r; j++) {
		if (array[j] <= x) {
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[r]);
	return i + 1;
}

void quickSort(int array[], int low, int high) {
	if (low < high) {
		int q = partition(array, low, high);
		quickSort(array, low, q - 1);
		quickSort(array, q + 1, high);
	}

}

void sort(int array[]) {
	quickSort(array, 0, 10);
}

int main(void) {
	int algos = 6;
	int tests = 6;

	cout << "quicksort" << endl;

	int test_sizes[] = { 10000, 50000, 100000, 300000, 500000, 600000 };

	int inputNumbers[700000];

	for (int x = 0; x < tests; x++) {
		inputNumbers[x] = rand() % 1000000;

		clock_t begin = clock();

		quickSort(inputNumbers, 0, test_sizes[x]);

		clock_t end = clock();

		double time = (double)(end - begin) / CLOCKS_PER_SEC;
		cout << time * 1000 << " ";

		for(int i = 0; i <  test_sizes[i]; i++) {
			cout << inputNumbers[i] << " ";
		}
	}

	cout << endl;

}
