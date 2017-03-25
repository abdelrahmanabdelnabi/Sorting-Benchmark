/*
 * quicksort.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: Abdelrahman Abdelnabi
 */

#include <iostream>

void sort(int array[]);
void quickSort(int array[], int low, int high);


void sort(int array[]) {
	quickSort(array, 0, (sizeof(array)/sizeof(int)));
}


void quickSort(int array[], int low, int high) {

}
