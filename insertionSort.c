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

