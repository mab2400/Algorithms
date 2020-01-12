# include <stdio.h>
# include <stdlib.h>

void print_array(int a[], size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        printf("%d\n", a[i]);
    }
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

