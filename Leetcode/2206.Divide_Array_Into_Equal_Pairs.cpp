#include <bits/stdc++.h>
using namespace std;

bool divideArray(vector<int> &nums)
{
    // nums consist of 2*n integers
    // divide nums into n pairs st each elem is in 1 pair only and no of elements present in each pair are equal
    int n = nums.size();
    // create n/2 pairs
    // check count of each num:
    unordered_map<int, int> hashMap;
    for (int i = 0; i < n; i++)
    {
        hashMap[nums[i]]++;
    }
    // for even count numbers possible to divide in pairs:
    for (auto it : hashMap)
    {
        if (it.second % 2 != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> nums1 = {3, 2, 3, 2, 2, 2};
    cout << "\nnums1 can be divided into n pairs= " << divideArray(nums1) << endl;
    vector<int> nums2 = {1, 2, 3, 4};
    cout << "\nnums2 can be divided into n pairs= " << divideArray(nums2) << endl;

    return 0;
}