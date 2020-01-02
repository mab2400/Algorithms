# include <stdio.h>
# include <stdlib.h>

void selectionSort(int a[], int size)
{
    /* pa now points to the first
     * element in the array to be 
     * sorted. */

    printf("Input Array: \n");

    for(int i=0; i<size; i++)
    {
        printf("%d\n", a[i]);
    }

    int *pa;
    pa = &a[0];

    for(int i=0; i<size; i++)
    {
        int minindex = i;
        int min = a[i];
        for(int j=i; j<size; j++)
        {
            if(a[j] < min)
            {
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
    int arr[argc-1];
    int i = 1;
    char *p;
    long longvalue;
    int value;

    /* Putting the command line args
     * as ints in the array */

    while(--argc > 0)
    {
        longvalue = strtol(argv[i], &p, 10);
        value = (int) longvalue;
        arr[i-1] = value;
        i++;
    }

    size_t s2 = sizeof(arr) / sizeof(arr[0]);
    int size2 = (int) s2;

    /* Here I will be calling
     * selectionSort() on the array. */
    
    selectionSort(arr, size2);

    printf("Sorted Array: \n");

    for(int i=0; i<size2; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}

