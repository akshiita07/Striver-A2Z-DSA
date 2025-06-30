#include <bits/stdc++.h>
using namespace std;

int findLHS(vector<int> &nums)
{
    // harmonious array : diff bw max & min value is exactly 1
    // return the length of its longest harmonious subsequence
    // sort array:
    sort(nums.begin(), nums.end());
    // {1,2,2,2,3,3,5,7}
    int n = nums.size();
    // take hash map:
    unordered_map<int, int> hashMap;
    for (int i = 0; i < n; i++)
    {
        hashMap[nums[i]]++;
    }
    int ans = 0;
    for (auto it : hashMap)
    {
        if (hashMap.find(it.first + 1) != hashMap.end())
        {
            // present 2 elements st diff is 1:
            // add their counts: hashMap[it.first] + hashMap[it.first+1]
            ans = max(ans, it.second + hashMap[it.first + 1]);
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << "\nlength OF Longest Harmonious Subsequence: " << findLHS(nums);

    return 0;
}