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
	int testArray[] = { 90, 44, 6, 72, 3, 1, 23, 15, 80, 0 };

	sort(testArray);

	for (int i = 0; i < sizeof(testArray) / sizeof(int); i++) {
		cout << testArray[i] << " ";
	}

	int algos = 6;
	// input sizes: 1000, 10000, 50000, 100000, 300000, 500000
	int tests = 6;

	int test_sizes[] = { 1000, 10000, 50000, 100000, 300000, 500000 };

	int durations[6][6];

	char names[][] = { "insertion", "selection", "bubble", "heap", "merge",
			"quick" };

	for (int i = 0; i < 6; i++) {
		// generate a random array of size test_sizes[i]
		int inputNumbers[];

		for(int x = 0; x < test_sizes[i]; i++) {
			inputNumbers[i] = rand() % 1000000;
		}

		for (int j = 0; j < 6; j++) {
			// measure execution time of jth algorithm
			int duration;

			// add to duration matrix
			durations[i][j] = duration;
		}
	}

	ofstream myfile;
	myfile.open("times.txt");
	myfile << "Writing this to a file.\n";
	myfile.close();

	myfile << algos << endl;
	myfile << tests << endl;

	for(int i = 0; i < tests; i++){
		myfile << test_sizes[i] << " ";
	}

	myfile << endl;

	for (int i = 0; i < algos; i++) {
		myfile << names[i] << endl;
		for(int j = 0; j < tests; i++) {
			myfile << durations[j][i] << " ";
		}

		myfile << endl;
	}

}
