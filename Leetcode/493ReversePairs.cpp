#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE- TIME-O(n^2)     SPACE:O(1)
int reversePairs_brute(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (j > i && nums[i] > 2 * nums[j])
            {
                count++;
            }
        }
    }

    return count;
}

// OPTIMAL      TIME-O(n^2)     SPACE:O(1)
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

int countRevPairs(vector<int> &arr, int low, int mid, int high)
{
    int count = 0;
    int j = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (j <= high && arr[i] > 2 * arr[j])
        {
            j++;
        }
        count += (j - (mid + 1));
    }
    return count;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int count=0;
    // base case
    if (low >= high)
    {
        return count;
    }
    int mid = (low + high) / 2;
    count+=mergeSort(arr, low, mid);
    count+=mergeSort(arr, mid + 1, high);
    count+=countRevPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return count;
}

int reversePairs_optimal(vector<int> &nums)
{
    int n = nums.size();
    int count = mergeSort(nums, 0, n - 1);

    return count;
}

int main()
{
    vector<int> nums = {2, 4, 3, 5, 1};
    // cout << "\nThe no of reverse pairs are: " << reversePairs_brute(nums) << endl;
    cout << "\nThe no of reverse pairs are: " << reversePairs_optimal(nums) << endl;

    return 0;
}