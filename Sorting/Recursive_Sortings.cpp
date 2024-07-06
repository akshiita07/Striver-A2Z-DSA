#include <bits/stdc++.h>
using namespace std;

// MERGE SORT- OPTIMAL!
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

int main()
{
    int arr[] = {3, 1, 2, 4, 1, 5, 2, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);

    cout << "\nThe merged array is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    // TIME COMPLEXITY OF MERGE SORT IS O(nlogn)

    return 0;
}