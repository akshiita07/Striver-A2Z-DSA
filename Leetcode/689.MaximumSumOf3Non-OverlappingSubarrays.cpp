#include <bits/stdc++.h>
using namespace std;

vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
{
    // 3 non overlapping subarrays of length k with max sum
    // return list of first indices in array
    vector<int> ans;
    int n = nums.size();
    // prefix sum array that stores sum of first i elements
    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    // left & right interval:
    vector<int> leftInterval(n, 0);  // 0 to i
    vector<int> rightInterval(n, 0); // i+1 to n

    int left_sum = prefixSum[k] - prefixSum[0];
    for (int i = k; i < n; i++)
    {
        if (prefixSum[i + 1] - prefixSum[i + 1 - k] > left_sum)
        {
            left_sum = prefixSum[i + 1] - prefixSum[i + 1 - k];
            leftInterval[i] = i + 1 - k;
        }
        else
        {
            leftInterval[i] = leftInterval[i - 1];
        }
    }

    int right_sum = prefixSum[n] - prefixSum[n - k];
    rightInterval[n - k] = n - k;
    for (int i = n - k - 1; i >= 0; i--)
    {
        if (prefixSum[i + k] - prefixSum[i] >= right_sum)
        {
            right_sum = prefixSum[i + k] - prefixSum[i];
            rightInterval[i] = i;
        }
        else
        {
            rightInterval[i] = rightInterval[i + 1];
        }
    }

    int maxi = 0;
    for (int i = k; i <= n - (2 * k); i++)
    {
        int l = leftInterval[i - 1];
        int r = rightInterval[i + k];
        int total = (prefixSum[i + k] - prefixSum[i]) + (prefixSum[l + k] - prefixSum[l]) + (prefixSum[r + k] - prefixSum[r]);
        if (total > maxi)
        {
            maxi = total;
            ans = {l, i, r};
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 6, 7, 5, 1};
    int k = 2;
    vector<int> ans = maxSumOfThreeSubarrays(nums, k);
    cout << "Ans:\n";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}