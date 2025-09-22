#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> hashMap;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            hashMap[nums[i]]++;
        }
        // now find max freq first:
        int maxi = INT_MIN;
        for (auto it : hashMap)
        {
            if (it.second > maxi)
            {
                maxi = it.second;
            }
        }
        // now we have maxfreq:
        int ans = 0;
        for (auto it : hashMap)
        {
            if (it.second == maxi)
            {
                ans += it.second;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}