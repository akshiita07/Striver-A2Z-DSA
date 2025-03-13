#include <bits/stdc++.h>
using namespace std;

bool canMakeZero(vector<int> &nums, vector<vector<int>> &queries, int k)
{
    int n = nums.size();
    // difference array:
    vector<int> diff(n + 1, 0);
    // first k queries using array:
    for (int i = 0; i < k; i++)
    {
        // queries[i] = [li, ri, vali]
        int l = queries[i][0];
        int r = queries[i][1];
        int val = queries[i][2];
        diff[l] -= val;
        diff[r + 1] += val;
    }
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += diff[i];
        if (nums[i] + prefixSum > 0)
        {
            return false;
        }
    }
    return true;
}

int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
{
    int left = 0;
    int right = queries.size();
    int ans = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (canMakeZero(nums, queries, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {};
    vector<vector<int>> queries = {};
    cout << "\nAns= " << minZeroArray(nums, queries) << endl;

    return 0;
}