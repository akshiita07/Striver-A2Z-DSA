#include <bits/stdc++.h>
using namespace std;

int countMaxOrSubsets(vector<int> &nums)
{
    // find number of subsets that have maximum bitwise OR
    // find all subsets & find max XOR:
    // find no of subsets with this max xor
    int n = nums.size();
    int maxOR = 0;
    int count = 0;

    // Iterate over all possible subsets using bitmasking
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int currentOR = 0;

        // Compute the OR for the current subset
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                currentOR = currentOR|nums[i];
            }
        }

        // Check if this subset has the maximum OR value
        if (currentOR > maxOR)
        {
            maxOR = currentOR;
            count = 1; // Reset count because we found a new maximum
        }
        else if (currentOR == maxOR)
        {
            count++; // Increment count for another subset with the same max OR
        }
    }

    return count;
}

int main()
{
    vector<int> nums = {3, 2, 1, 5};
    cout<<"\nNo of subsets with maximum Xor are: "<<countMaxOrSubsets(nums);
    return 0;
}