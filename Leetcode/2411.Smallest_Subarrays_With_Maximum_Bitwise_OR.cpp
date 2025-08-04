#include <bits/stdc++.h>
using namespace std;

vector<int> smallestSubarrays(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    vector<int> lastSeen(32, -1);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 32; j++)
        {
            if ((nums[i] >> j) & 1)
            {
                lastSeen[j] = i;
            }
        }

        // Find farthest index we need to include
        int farthest = i;
        for (int j = 0; j < 32; j++)
        {
            if (lastSeen[j] != -1)
            {
                farthest = max(farthest, lastSeen[j]);
            }
        }

        ans[i] = farthest - i + 1;
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 0, 2, 1, 3};
    vector<int> ans = smallestSubarrays(nums);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}