#include <bits/stdc++.h>
using namespace std;

int triangularSum(vector<int> &nums)
{
    // nums[i] is a digit between 0 and 9
    int n = nums.size();
    while (n != 1)
    {
        // create new array newNums of size n-1
        vector<int> newNums(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            newNums[i] = (nums[i] + nums[i + 1]) % 10;
        }
        // replace nums with newNums
        nums = newNums;
        // update size of array:
        n = nums.size();
    }
    // Return the triangular sum of nums: ie the last single element
    // remaining
    return nums[0];
}

int main()
{
    vector<int> nums = {};

    return 0;
}