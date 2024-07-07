#include <bits/stdc++.h>
using namespace std;

// MERGE SORT- OPTIMAL! : O(nlogn) time & O(n) space
void merge(int arr[], int low, int mid, int high)
{
    // take 2 divided arrays & merge them into 1
    vector<int> mergedArray;
    // 2 pointers to traverse thru array
    int i = low;
    int j = mid + 1;
    while (i <= mid && j <= high) // jab tak dono mai elements hai
    {                             // until 1 array finishes
        if (arr[i] <= arr[j])
        {
            mergedArray.emplace_back(arr[i]);
            i++;
        }
        else
        {
            mergedArray.emplace_back(arr[j]);
            j++;
        }
    }
    // push all remaining elements
    for (; i <= mid; i++)
    {
        mergedArray.emplace_back(arr[i]);
    }
    for (; j <= high; j++)
    {
        mergedArray.emplace_back(arr[j]);
    }

    cout << "\nThe merged VECTORS is: \n";
    for (auto it : mergedArray)
    {
        cout << it << " ";
    }

    // add this merged array into arr
    for (int i = low; i <= high; i++)
    {
        arr[i] = mergedArray[i - low];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    // divide array into 2 halves
    // low-0 high-(n-1) mid->break
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    // & then send them to merge
    merge(arr, low, mid, high); // 1st half- low to mid & 2nd half- mid+1 to high
}

// QUICK SORT-
// CHOOSE PIVOT AS FIRST ELEMENT-> PUT PIVOT IN ITS SORTED POSITITON-> SMALLER ON LEFT -> GREATER ON RIGHT
int findPivot(int arr[], int low, int high)
{
    int pivot = arr[low]; // first element-0
    int i = low;
    int j = high;
    while (i < j)
    {
        // find elem greater than pivot using i
        while (arr[i] <= pivot && i < high)
        {
            i++;
        }
        // find arr[j] > arr[pivot]elem smaller than pivot using j
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    // if j croses i then swap pivot with j
    swap(arr[low], arr[j]);

    return j; // partioning positon at j
}
// QUICK SORT ON LEFT SUBARRAY-> QUICK SORT ON RIGHT SUBARRAY
void quickSort(int arr[], int low, int high)
{
    // base case
    if (low >= high)
    {
        return;
    }
    int partitionIndex = findPivot(arr, low, high);
    // left subarray
    quickSort(arr, low, partitionIndex - 1);
    // right subarray
    quickSort(arr, partitionIndex + 1, high);
}

int main()
{
    // int arr[] = {3, 1, 2, 4, 1, 5, 2, 6, 4};             //merge
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3}; // quick
    int n = sizeof(arr) / sizeof(arr[0]);
    // mergeSort(arr, 0, n - 1);
    quickSort(arr, 0, n - 1);

    cout << "\nThe SORTED array is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    // TIME COMPLEXITY OF MERGE SORT IS O(nlogn)    SPACE-O(n)- extra temp array reqd for merge
    // TIME COMPLEXITY OF QUCIK SORT IS O(nlogn)    SPACE-O(1)                                          OPTIMAL

    return 0;
}