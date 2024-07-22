#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE- TIME:O(n^2)     SPACE:O(1)-constant space
int numberOfInversions_brute(vector<int> &arr)
{
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i < j && arr[i] > arr[j])
            {
                count++;
            }
        }
    }

    return count;
}

int c = 0; // global variable
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            // left>right
            c += (mid - i + 1);
            j++;
        }
    }
    // remaining
    for (; i <= mid; i++)
    {
        temp.push_back(arr[i]);
    }
    for (; j <= high; j++)
    {
        temp.push_back(arr[j]);
    }

    // transfer from temp array back to arr
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void mergeSort(vector<int> &arr, int low, int high)
{
    // base case
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
// OPTIMAL- TIME:O()     SPACE:O(1)-constant space
int numberOfInversions_optimal(vector<int> &arr)
{
    int n = arr.size();

    // using merge sort
    mergeSort(arr, 0, n - 1);

    return c;
}

int main()
{
    vector<int> arr = {5, 3, 2, 1, 4};
    // cout << "\nThe number of inversions are: " << numberOfInversions_brute(arr) << endl;
    cout << "\nThe number of inversions are: " << numberOfInversions_optimal(arr) << endl;

    return 0;
}