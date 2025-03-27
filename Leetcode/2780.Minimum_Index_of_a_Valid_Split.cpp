#include <bits/stdc++.h>
using namespace std;

int minimumIndex(vector<int> &nums)
{
    int n = nums.size();
    // 1 dominant element x present:more than half elements of array have value x
    // split array only if nums[0_ _ i] and nums[i+1 _ _ n-1] have same dominant element
    // Return the minimum index of a valid split
    unordered_map<int, int> hashMap;
    for (int i = 0; i < n; i++)
    {
        hashMap[nums[i]]++;
    }
    int x;
    int f = INT_MIN; // dominant element & its frequency
    for (auto it : hashMap)
    {
        if (it.second > f)
        {
            f = it.second;
            x = it.first;
        }
    }
    cout << "\nDominant element is " << x << " with frequency " << f;

    // let frequency of dominant element x in left subarray be f1 then frequency of dominant element x in right subarray will be f2=f-f1
    int f1 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] == x)
        {
            f1++;
        }
        int leftSize = i + 1;
        int rightSize = n - leftSize;
        int f2 = f - f1; // freq of x in right subarry:
        // check if dominant in both subarrays:
        if (f1 > (leftSize / 2) && f2 > (rightSize / 2))
        {
            return i; // valid split index
        }
    }
    // else:
    return -1;
}

int main()
{
    vector<int> nums = {2, 1, 3, 1, 1, 1, 7, 1, 2, 1};
    cout << "\nminimum index of a valid split= " << minimumIndex(nums);
    return 0;
}