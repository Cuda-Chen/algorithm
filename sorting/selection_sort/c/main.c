#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int m = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[m])
            {
                m = j;
            }
        }

        if(i != m)
        {
            swap(&arr[i], &arr[m]);
        }
    }
}

void printArray(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int array[] = {5,3,8,6,2,7,1,4};
    int arraySize = 8;

    selectionSort(array, arraySize);
    printArray(array, arraySize);

    return 0;
}
