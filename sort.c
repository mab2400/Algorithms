# include <stdio.h>
# include <stdlib.h>
# include "sort.h"

  void print_array(int a[], size_t size)
  {
      for(size_t i = 0; i < size; ++i)
      {
          printf("%d\n", a[i]);
      }
  }

  void insertionSort(int a[], int size)
  {
      /* 
          i moves forward in the unsorted portion
          j moves backward in the sorted portion 
          (j starts out in the same position as i)
          use j to repeatedly swap backward.
          use i to pick the next element to swap down. */

      for(size_t i = 0; i < size; ++i)
      {
          /* i delineates the border between
          sorted and unsorted portions. */

          for(size_t j=i; j>=1; --j)
          {
              if(a[j] < a[j-1])
              {
                  /* Swapping a[j] and a[j-1] */
                  int temp = a[j];
                  a[j] = a[j-1];
                  a[j-1] = temp;
              }
          }
      }
  }

  void merge(int arr[], size_t size, size_t leftPos, size_t rightPos, size_t rightEnd)
  {
      // declare a new array called tmp, 
      // with same length as arr[]

      int *tmp = malloc(size * sizeof(int));

      size_t aCtr = leftPos;
      size_t bCtr = rightPos;
      size_t cCtr = leftPos;

      while(aCtr < rightPos && bCtr <= rightEnd)
      {
          if(arr[aCtr] <= arr[bCtr])
          {
              tmp[cCtr++] = arr[aCtr++];
          } else {
              tmp[cCtr++] = arr[bCtr++];
          }
      }

      // Copying the remaining elements into
      // the right partition

      if(aCtr >= rightPos)
      {
          while(bCtr <= rightEnd)
          {
              tmp[cCtr++] = arr[bCtr++];
          }
      }

      // Copying the remaining elements into
      // the left partition

      if(bCtr > rightEnd)
      {
          while(aCtr < rightPos)
          {
              tmp[cCtr++] = arr[aCtr++];
          }
      }

      for(size_t i = leftPos; i <= rightEnd; i++)
      {
          arr[i] = tmp[i];
      }
  }

  void mergeSort(int arr[], size_t size, size_t left, size_t right)
  {
      if((right - left) < 1)
      {
          return;
      }

      // Might need to rewrite this line
      // due to possible overflow(??)

      size_t rightPos = (left + right) / 2;

      // Using recursion to sort each half

      mergeSort(arr, size, left, rightPos);
      mergeSort(arr, size, rightPos + 1, right);

      // Merge
      merge(arr, size, left, rightPos + 1, right);

  }

  void mergeSort2(int arr[], size_t size)
  {
      mergeSort(arr, size, 0, size - 1);
  }

  void selectionSort(int a[], int size)
  {
      for (size_t i = 0; i < size; ++i) {
          int minindex = i;
          int min = a[i];
          for(int j = i; j < size; ++j) {
              if(a[j] < min) {
                  min = a[j];
                  minindex = j;
              }
          }

          /* Swapping min and a[i] */

          int temp = a[minindex];
          a[minindex] = a[i];
          a[i] = temp;
      }

  }
