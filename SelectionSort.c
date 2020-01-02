# include <stdio.h>

int * selectionSort(int a[])
{
    /* This method returns a pointer
     * to the first element
     * in the sorted array.*/

    /* pa now points to the first
     * element in the array to be 
     * sorted. */

    int *pa;
    pa = &a[0];

    int size = sizeof(a) / sizeof(a[0]);

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

    return pa;
}

int main(int argc, char *argv[])
{
    int arr[argc-1];

    /* Putting the command line args
     * as ints in the array */

    while(--argc > 0)
    {
        int value = *++argv - '0';
        int i = 0;
        arr[i++] = value;
    }

    /* Here I will be calling
     * selectionSort() on the array. */
    
    int *result = selectionSort(arr);

    int size = sizeof(arr) / sizeof(arr[0]);

    for(int i=0; i<size; i++)
    {
        printf("%d\n", *result++);
    }

    return 0;
}

