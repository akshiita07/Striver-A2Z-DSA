#include <bits/stdc++.h>
using namespace std;

int maxIncreasingSubarrays(vector<int> &nums)
{
    int n = nums.size();
    // 2 adjacent k length subarrays strictly increasing
    // return max value of k:
    if (n < 2)
    {
        return 0;
    }
    vector<int> left(n, 1);
    vector<int> right(n, 1);

    // length of increasing run ending at i
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            left[i] = left[i - 1] + 1;
        }
    }

    // length of increasing run starting at i
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            right[i] = right[i + 1] + 1;
        }
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1 || nums[i] >= nums[i + 1])
        {
            int runLen = left[i];
            k = max(k, runLen / 2);
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] >= nums[i + 1])
        {
            k = max(k, min(left[i], right[i + 1]));
        }
    }
    return k;
}

int main()
{

    return 0;
}