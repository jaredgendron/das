#pragma once

class Sort {
  private: 
    void swap(int *xptr, int *yptr);
  public: 
    void insertion(int arr[], int n);
    void selection(int arr[], int n);
    void bubble(int arr[], int n);
    void printArray(int arr[], int n);
};