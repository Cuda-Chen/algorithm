// https://www.geeksforgeeks.org/heap-sort/

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int *arr, int n, int i)
{
    int largest = i; // initialize largest as root
    int left = 2 * i + 1; 
    int right = 2 * i + 2;

    // if left child is larger than root
    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    // if right child is larger than root
    if(right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // if largest is not root
    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n)
{
    // build max-heap
    for(int i = n / 2; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }

    // get element one by one
    for(int i = n - 1; i > 0; i--)
    {
        // move current root to end
        swap(&arr[0], &arr[i]);

        // call maxHeapify() on the reduced heap
        maxHeapify(arr, i, 0);
    }
}

void printArray(int *arr, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int array[] = {5,3,8,6,2,7,1,4};
    int arraySize = 8;

    printArray(array, arraySize);

    heapSort(array, arraySize);
    printArray(array, arraySize);

    return 0;
}
