#include <bits/stdc++.h>
using namespace std;

int findSmallestInteger(vector<int> &nums, int value)
{
    // add or subtract value from any element of nums
    // MEX (minimum excluded) of an array is the smallest missing non-negative integer
    // Return the maximum MEX of nums
    unordered_map<int, int> freq;
    for (auto it : nums)
    {
        int remain = ((it % value) + value) % value;
        freq[remain]++;
    }

    int mex = 0;
    while (true)
    {
        int remain = mex % value;
        if (freq[remain] > 0)
        {
            freq[remain]--;
        }
        else
        {
            break;
        }
        mex++;
    }
    return mex;
}

int main()
{

    return 0;
}