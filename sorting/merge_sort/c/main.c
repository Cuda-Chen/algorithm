// https://www.geeksforgeeks.org/merge-sort/

#include <stdio.h>

// left subarray is array[left..mid]
// right subarray is array[mid + 1..right]
void merge(int *array, int left, int mid, int right)
{
    int leftMostIdx = mid - left + 1;
    int rightMostIdx = right - mid;
    int leftSide[leftMostIdx];
    int rightSide[rightMostIdx];

    for(int i = 0; i < leftMostIdx; i++)
    {
        leftSide[i] = array[left + i];
    }
    for(int i = 0; i < rightMostIdx; i++)
    {
        rightSide[i] = array[mid + 1 + i];
    }

    int leftIdx = 0, rightIdx = 0;
    int k = left;
    while(leftIdx < leftMostIdx && rightIdx < rightMostIdx)
    {
        if(leftSide[leftIdx] < rightSide[rightIdx])
        {
            array[k] = leftSide[leftIdx];
            leftIdx++;
        }
        else
        {
            array[k] = rightSide[rightIdx];
            rightIdx++;
        }

        k++;
    }

    // copy the remaining elements of leftSide[]
    while(leftIdx < leftMostIdx)
    {
        array[k] = leftSide[leftIdx];
        leftIdx++;
        k++;
    }
    // copy the remaining elements of rightSide[]
    while(rightIdx < rightMostIdx)
    {
        array[k] = rightSide[rightIdx];
        rightIdx++;
        k++;
    }
}

void mergeSort(int *array, int left, int right) 
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
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
    mergeSort(arr, 0, arrSize - 1);
    printf("sorted: \n");
    printArray(arr, arrSize);

    return 0;
}
