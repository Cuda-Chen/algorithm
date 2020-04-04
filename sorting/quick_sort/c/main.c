// http://alrightchiu.github.io/SecondRound/comparison-sort-quick-sortkuai-su-pai-xu-fa.html

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;
    for(int j = left; j < right; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    i++;
    swap(&arr[i], &arr[right]);
    return i;
}

void quickSort(int *arr, int left, int right)
{
    if(left < right)
    {
        int pivotIdx = partition(arr, left, right);
        quickSort(arr, left, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, right);
    }
}

void printArray(int *array, int arraySize)
{
    for(int i = 0; i < arraySize; i++)
    {   
        printf("%d ", array[i]);
    }   
    printf("\n");
}

int main()
{
    int arr[] = {5,3,8,6,2,7,1,4};
    int arrSize = 8;

    printf("original: \n");
    printArray(arr, arrSize);
    quickSort(arr, 0, arrSize - 1); 
    printf("sorted: \n");
    printArray(arr, arrSize);

    return 0;
}
