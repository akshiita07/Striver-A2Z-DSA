#include <bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int> &nums)
{
    // return subarrays of length 3 s.t. sum of 1st and 3rd no = half of 2nd no.
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n - 2; i++)
    {
        if ((nums[i] + nums[i + 2]) * 2 == nums[i + 1])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    vector<int> nums = {1, 2, 1, 4, 1};
    cout << "\nThe count of fixed-bound subarrays is: " << countSubarrays(nums);

    return 0;
}