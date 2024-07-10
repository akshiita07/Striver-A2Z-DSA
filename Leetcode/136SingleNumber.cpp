#include <bits/stdc++.h>
using namespace std;

// using O(n^2)time             space:O(1)
int singleNumberBruteForce(int nums[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
        }
        if (count == 1)
        {
            return nums[i];
        }
    }
}

// BETTER- using extra hash space O(max_elem)          time:O(n+n+max_elem)
int singleNumber_Better(int nums[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }
    // maintain count for each no in array
    int hasharr[max] = {0};
    for (int i = 0; i < n; i++)
    {
        hasharr[nums[i]]++;
    }
    // count<2 print
    for (int i = 0; i < max; i++)
    {
        if (hasharr[i] == 1)
        {
            return i;
        }
    }
}

// optimal using XOR
int singleNumber(int nums[], int n)
{
    int XOR=0;
    for (int i = 0; i < n; i++)
    {
        XOR = XOR^nums[i];
    }
    return XOR;
}

int main()
{
    // int arr[] = {2, 2, 1};
    int arr[] = {4, 1, 2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << "The no that occurrs only once is brute force: " << singleNumberBruteForce(arr, n);
    // cout << "The no that occurrs only once is better: " << singleNumber_Better(arr, n);
    cout << "The no that occurrs only once is optimal: " << singleNumber(arr, n);

    return 0;
}