#include <bits/stdc++.h>
using namespace std;

int brute_force(vector<int> &nums)
{
    // nice subarray: subarray with bitwise AND of elements=0
    // Return the length of the longest nice subarray.
    // subarrays of length=1 are ALWAYS nice
    int n = nums.size();
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            bool isNice = true;
            for (int k = i; k <= j; k++)
            {
                for (int l = k + 1; l <= j; l++)
                {
                    if ((nums[k] & nums[l]) != 0)
                    {
                        isNice = false;
                    }
                }
                if (isNice == false)
                {
                    break;
                }
            }
            if (isNice == true)
            {
                ans = max(ans, j - i + 1);
            }
        }
    }
    return ans;
}

bool isValid(int num, unordered_set<int> &bits)
{
    for (int bit = 0; bit < 30; bit++) // iterate over each bit position from 0 to 29
    {
        // shift binary 1: 0001 to left side 'bit' no of times
        if ((num & (1 << bit)) && (bits.count(1 << bit))) // check if bit is set & has been used before or not
        {
            return false;
        }
    }
    return true;
}

int longestNiceSubarray(vector<int> &nums)
{
    // nice subarray: subarray with bitwise AND of elements=0
    // Return the length of the longest nice subarray.
    // subarrays of length=1 are ALWAYS nice
    int n = nums.size();
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> bits;
        for (int j = i; j < n; j++)
        {
            if (!isValid(nums[j], bits))
            {
                break;
            }
            // insert individual bits of nums[j] into set
            for (int bit = 0; bit < 30; bit++)
            {
                if (nums[j] & (1 << bit))
                {
                    bits.insert(1 << bit);
                }
            }
            ans = max(ans, j - i + 1);
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 8, 48, 10};
    cout << "\nbrute_forcelength of the longest nice subarray= " << brute_force(nums);
    cout << "\nlength of the longest nice subarray= " << longestNiceSubarray(nums);

    return 0;
}