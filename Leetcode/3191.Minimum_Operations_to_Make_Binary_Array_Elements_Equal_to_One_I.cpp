#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums)
{
    // choose 3 consecutive elements & flip all
    // Return minimum number of operations reqd to make all elements in nums= 1 else return -1
    int n = nums.size();
    int ans = 0;
    // greedy approach
    //  if num is 0 then flip 3 elements
    for (int i = 0; i < n - 2; i++)
    {
        if (nums[i] == 0)
        {
            // FLIP BITS: take XOR with 1: 1^1=0, 0^1=1
            nums[i] ^= 1;
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
            ans++;
            cout << "\nFlipped";
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            // not successful
            return -1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {0, 1, 1, 1, 0, 0};
    cout << "\nminimum number of operations= " << minOperations(nums);

    return 0;
}