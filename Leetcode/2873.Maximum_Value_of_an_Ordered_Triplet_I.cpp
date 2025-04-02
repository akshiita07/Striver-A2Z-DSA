#include <bits/stdc++.h>
using namespace std;

long long maximumTripletValue(vector<int> &nums)
{
    long long tripVal = 0;
    long long maxVal = LLONG_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if ((i < j) && (j < k))
                {
                    tripVal = (long long)(nums[i] - nums[j]) * nums[k];
                    maxVal = max(maxVal, tripVal);
                }
            }
        }
    }
    // if triplets have a negative value, return 0
    if (maxVal < 0)
    {
        // negative val:
        return 0;
    }
    return maxVal;
}

int main()
{
    vector<int> nums = {12, 6, 1, 2, 7};
    cout << "\nMaximum triplet value: " << maximumTripletValue(nums);

    return 0;
}