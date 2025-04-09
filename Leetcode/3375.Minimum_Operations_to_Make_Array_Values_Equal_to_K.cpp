#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums, int k)
{
    int n = nums.size();
    // if array contains integer less than k: not possible so return -1
    for (auto it : nums)
    {
        if (it < k)
        {
            return -1;
        }
    }
    // else:
    // answer is no of distinct elements in array greater than k
    unordered_map<int, int> hashMap;
    for (auto it : nums)
    {
        hashMap[it]++;
    }
    int count = 0;
    for (auto it : hashMap)
    {
        if (it.first > k)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    vector<int> nums = {5, 2, 5, 4, 5};
    int k = 2;
    cout << "\nMinimum operations to make all elements equal to k: " << minOperations(nums, k);

    return 0;
}