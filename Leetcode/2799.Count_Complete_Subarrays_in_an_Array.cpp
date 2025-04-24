#include <bits/stdc++.h>
using namespace std;

int countCompleteSubarrays(vector<int> &nums)
{
    // no of distinct elements in subarray=no of distinct elements in whole array
    // return the number of complete subarrays
    int k = 0;
    unordered_map<int, int> hashMap;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        hashMap[nums[i]]++;
    }
    for (auto it : hashMap)
    {
        k++;
    }
    cout << "\nNo of distnict elements in whole array: " << k;
    int count = 0;
    // now find no of subarrays with k distinct elements:
    for (int i = 0; i < n; i++)
    {
        set<int> st;
        for (int j = i; j < n; j++)
        {
            // in this subarray cnt no of distinct elements:
            st.insert(nums[j]);
            if (st.size() == k)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<int> nums = {1, 3, 1, 2, 2};
    cout << "\nCount of complete subarrays: " << countCompleteSubarrays(nums) << "\n";
    return 0;
}