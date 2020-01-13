# include <stdio.h>
# include <stdlib.h>

/* Insertion Sort Algorithm:
Take the first element in unsorted portion
and swap it left until it is sorted.

1 2 4 9 | 3 7  (i=4, j=4, check if a[j]<a[j-1])
1 2 4 3 9 | 7  (i=4, j=3, check if a[3]<a[2])
I know i still have to keep swapping left
because the element to the left of 3, aka 4, 
is greater than 3. 
1 2 3 4 9 | 7  
*/

void print_array(int a[], size_t size)
{
    for(size_t i = 0; i < size; ++i)
    {
        printf("%d\n", a[i]);
    }
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
     * insertionSort() on the array. */
    
    insertionSort(arr, size);

    printf("Sorted Array: \n");
    print_array(arr, size);

    return 0;
}

