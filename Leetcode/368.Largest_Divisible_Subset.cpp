#include <bits/stdc++.h>
using namespace std;

// classic DP + Sorting problem
vector<int> largestDivisibleSubset(vector<int> &nums)
{
    // return largest subset answer (answer[i],answer[j]) st answer[i] % answer[j] == 0 OR answer[j] % answer[i] == 0
    int n = nums.size();
    if (n == 0)
    {
        return {};
    }
    // sort given array:
    sort(nums.begin(), nums.end());
    vector<int> dp(n, -1);
    vector<int> prev(n, -1);
    int maxIndex = 0;
    for (int i = 1; i < n; i++) // from 1 element aage
    {
        for (int j = 0; j < i; j++) // from 0 to i-1 wale elements
        {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > dp[maxIndex])
        {
            maxIndex = i;
        }
    }
    vector<int> answer;
    while (maxIndex >= 0)
    {
        answer.push_back(nums[maxIndex]);
        maxIndex = prev[maxIndex];
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<int> nums = {1, 2, 4, 8, 7};
    vector<int> ans = largestDivisibleSubset(nums);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}