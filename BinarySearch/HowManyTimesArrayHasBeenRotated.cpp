#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int minEle = INT_MAX;
    int rotatedIndex;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[high])
        {
            // full array sorted
            if (arr[low] <= minEle)
            {
                minEle = arr[low];
                rotatedIndex = low;
            }
            break;
        }
        if (arr[low] <= arr[mid])
        {
            // left sorted
            // right unsorted
            if (arr[low] <= minEle)
            {
                minEle = arr[low];
                rotatedIndex = low;
            }
            low = mid + 1;
        }
        else
        {
            if (arr[mid] <= minEle)
            {
                minEle = arr[mid];
                rotatedIndex = mid;
            }
            high = mid - 1;
        }
    }
    return rotatedIndex;
}

int main()
{
    // original array: {2,4,6,9}    so rotated 2 times
    vector<int> arr = {6, 9, 2, 4};
    cout << "\nThis array has been rotated for " << findKRotation(arr) << " no of times.";
    return 0;
}