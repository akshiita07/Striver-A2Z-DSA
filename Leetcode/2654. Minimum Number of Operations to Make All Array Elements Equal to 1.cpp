#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums)
{
    int n = nums.size();
    int ones = 0;
    for (int x : nums)
    {
        if (x == 1)
        {
            ones++;
        }
    }

    if (ones > 0)
    {
        return n - ones;
    }

    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int g = nums[i];
        for (int j = i + 1; j < n; j++)
        {
            g = gcd(g, nums[j]);
            if (g == 1)
            {
                ans = min(ans, j - i);
                break;
            }
        }
    }

    if (ans == INT_MAX)
    {
        return -1;
    }

    return ans + n - 1;
}

int main()
{

    return 0;
}