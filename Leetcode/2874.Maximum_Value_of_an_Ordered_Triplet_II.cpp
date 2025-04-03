#include <bits/stdc++.h>
using namespace std;

long long brute_force(vector<int> &nums)
{
    long long maxVal = LLONG_MIN;
    long long value = 0;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                value = (nums[i] - nums[j]) * nums[k];
                maxVal = max(maxVal, value);
            }
        }
    }
    if (maxVal < 0)
    {
        return 0;
    }
    return maxVal;
}

long long maximumTripletValue(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
    {
        // atleast 3 elments are reqd
        return 0;
    }
    // prefix max array:
    vector<int> prefixMax(n, 0);
    prefixMax[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefixMax[i] = max(prefixMax[i - 1], nums[i]);
    }
    // suffix max array:
    vector<int> suffixMax(n, 0);
    suffixMax[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixMax[i] = max(suffixMax[i + 1], nums[i]);
    }
    // compute max val
    long long maxVal = 0;
    for (int i = 1; i < n - 1; i++)
    {
        long long value = (long long)(prefixMax[i - 1] - nums[i]) * suffixMax[i + 1];
        maxVal = max(maxVal, value);
    }
    return maxVal;
}

int main()
{
    vector<int> nums = {12, 6, 1, 2, 7};
    cout << "\nMaximum value of an ordered triplet is " << maximumTripletValue(nums);

    return 0;
}