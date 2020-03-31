#include <stdio.h>

void insert(int key, int *arr, int i)
{
    while(key < arr[i])
    {
        arr[i + 1] = arr[i];
        i--;
    }

    arr[i + 1] = key;
}

void insertionSort(int *arr, int n)
{
    for(int i = 1; i < n; i++)
    {
        insert(arr[i], arr, i - 1);
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
    int array[] = {5, 3, 8, 6, 2, 7, 1, 4};
    int arraySize = 8;

    insertionSort(array, arraySize);
    printArray(array, arraySize);

    return 0;
}
