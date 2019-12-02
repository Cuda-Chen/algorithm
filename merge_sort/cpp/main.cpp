#include <iostream>
#include <vector>
using namespace std;

const int Max = 10000;

void merge(vector<int> &array, int left, int mid, int right)
{
    vector<int> leftSide(array.begin() + left, array.begin() + mid + 1);
    vector<int> rightSide(array.begin() + mid + 1, array.begin() + right + 1);

    leftSide.insert(leftSide.end(), Max);
    rightSide.insert(rightSide.end(), Max);

    int leftIdx = 0, rightIdx = 0;

    for(int i = left; i <= right; i++)
    {
        if(leftSide[leftIdx] < rightSide[rightIdx])
        {
            array[i] = leftSide[leftIdx];
            leftIdx++;
        }
        else
        {
            array[i] = rightSide[rightIdx];
            rightIdx++;
        }
    }
}

void mergeSort(vector<int> &array, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void printArray(vector<int> &array)
{
    for(int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {5,3,8,6,2,7,1,4};
    vector<int> array(arr, arr + sizeof(arr) / sizeof(int));

    cout << "original: " << endl;
    printArray(array);

    mergeSort(array, 0, array.size() - 1);
    cout << "sorted: " << endl;
    printArray(array);

    return 0;
}
