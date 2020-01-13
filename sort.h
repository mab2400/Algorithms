#ifndef _SORT_H_
#define _SORT_H_

  void print_array(int a[], size_t size);

  void insertionSort(int a[], int size);

  void merge(int arr[], size_t size, size_t leftPos, size_t rightPos, size_t rightEnd);

  void mergeSort(int arr[], size_t size, size_t left, size_t right);

  void mergeSort2(int arr[], size_t size);

  void selectionSort(int a[], int size);

#endif
