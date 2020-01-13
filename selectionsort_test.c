# include <stdio.h>
# include <stdlib.h>
# include "sort.h"

int main(int argc, char *argv[])
{
    size_t size = argc - 1; // size of array
    int *arr = malloc(size * sizeof(int)); // heap-allocated array of ints

    /* Putting the command line args
     * as ints in the array */

    for (size_t i = 0; i < size; ++i) {
        arr[i] = atoi(argv[i + 1]);
    }

    printf("Input Array: \n");
    print_array(arr, size);

    /* Here I will be calling
     * selectionSort() on the array. */
    
    selectionSort(arr, size);

    printf("Sorted Array: \n");
    print_array(arr, size);

    return 0;
}

