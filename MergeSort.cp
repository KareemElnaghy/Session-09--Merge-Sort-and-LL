//
//  main.cpp
//  LinkedList
//
//  Created by Esraa Hamdi Abbas on 11/1/21.
//
#include "LL.hpp"
#include <iostream>
#include <string.h>
using namespace std;
const int length = 6;
void merge(int arr[], int start, int m, int end) {
  int i = start; // start of first half
  int j = m + 1; // start of second half
  int k = start;

  /* create temp array */
  int temp[length];

  while (i <= m && j <= end) {
    if (arr[i] <= arr[j]) {
      temp[k] = arr[i];
      i++;
      k++;
    } else {
      temp[k] = arr[j];
      j++;
      k++;
    }

  }

  /* Copy the remaining elements of first half, if there are any */
  while (i <= m) {
    temp[k] = arr[i];
    i++;
    k++;

  }

  /* Copy the remaining elements of second half, if there are any */
  while (j <= end) {
    temp[k] = arr[j];
    j++;
    k++;
  }

  /* Copy the temp array to original array */
  for (int p = start; p <= end; p++) {
    arr[p] = temp[p];
  }
}

/* start is for left index and end is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int start, int end) {
  if (start< end) {
    // find midpoint
    int m = (start+ end) / 2;

    // recurcive mergesort first and second halves
    mergeSort(arr, start, m);
    mergeSort(arr, m + 1, end);

    // merge
    merge(arr, start, m, end);
  }
}


