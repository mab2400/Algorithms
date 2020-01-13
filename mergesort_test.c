# include <stdio.h>
# include <stdlib.h>

/* Merge Sort Algorithm:
 
merge(arr[], leftPos, rightPos, rightEnd)
mergeSort(arr[])
mergeSort(arr[], left, right)
In the main method I will call mergeSort on the 
entire array.

*/

void print_array(int a[], size_t size)
{
    for(size_t i = 0; i < size; ++i)
    {
        printf("%d\n", a[i]);
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


int main(int argc, char *argv[])
{
    size_t size = argc - 1; // size of array
    int *arr = malloc(size * sizeof(int)); 
    // heap-allocated array of ints

    /* Putting the command line args
     * as ints in the array */

    for(size_t i = 0; i < size; ++i)
    {
        arr[i] = atoi(argv[i + 1]);
    }

    printf("Input Array: \n");
    print_array(arr, size);
    
    /* Here I will be calling
     * mergeSort() on the array. */
    
    mergeSort2(arr, size);

    printf("Sorted Array: \n");
    print_array(arr, size);

    return 0;
}

