//
//  sorting.cpp
//  LinkedList
//
//  Created by Esraa Hamdi Abbas on 11/1/21.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int partition ( int a[] , int start,int end)
{
    //assign the last element to pivot
    int pivot = a[end];
    int pIndex = start; // partition index
    for (int i= start; i<end;i++)
    {
        if (a[i]< pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap (a[pIndex],a[end]);
    return pIndex;
}
void quicksort(int a[], int start, int end)
{
    if (start<end)
    {
        int pIndex = partition(a, start, end);
        quicksort(a,start,pIndex-1);
        quicksort(a,pIndex+1,end);
    }
}

