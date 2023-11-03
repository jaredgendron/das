#include "sort.hpp"
#include <stdio.h>

void Sort::swap(int *xptr, int *yptr)
{
  int temp = *xptr;
  *xptr = *yptr;
  *yptr = temp;
}

void Sort::insertion(int arr[], int n)
{
  int i, j, key;
  for (i=1; i<n; i++)
  {
    key = arr[i];
    j = i-1;
    while (j>= 0 && arr[j]>key)
    {
      arr[j+1] = arr[j];
      j = j-1;
    }
    arr[j+1] = key;
  }
  return;
}

void Sort::selection(int arr[], int n)
{
  int i, j, min;
  for(i=0;i<n-1;i++){
    min = i;
    for(j=i+1;j<n;j++){
      if(arr[j] < arr[min]){
        min = j;
      }
    }
    swap(&arr[min], &arr[i]);
  }
  return;
}

void Sort::bubble(int arr[], int n)
{
  int i, j;
  bool swapped;
  for(i=0; i<n-1; i++){
    swapped = false;
    for(j=0; j<n-i-1; j++){
      if(arr[j]>arr[j+1]){
        swap(&arr[j], &arr[j+1]);
        swapped = true;
      }
    } 
    if (swapped == false){
      break;
    }
  }
}

void Sort::printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}