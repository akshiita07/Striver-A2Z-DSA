#include <bits/stdc++.h>
using namespace std;

int brute_force(vector<int> &nums)
{
    int n = nums.size();
    // subarray from nums that has maximum possible bitwise AND.
    // k be the maximum value of the bitwise AND of any subarray of nums
    // Return the length of the longest such subarray
    int len = 0;
    int maxBitwiseAnd = INT_MIN;

    // generate all subarrays
    for (int i = 0; i < n; i++)
    {
        int bitwiseAnd = nums[i];
        for (int j = i; j < n; j++)
        {
            // find bitwise and
            bitwiseAnd = bitwiseAnd & nums[j];
            // check which has maxm
            if (maxBitwiseAnd < bitwiseAnd)
            {
                // update maxm one
                maxBitwiseAnd = bitwiseAnd;
                // return its length
                len = j - i + 1;
            }
            else if (maxBitwiseAnd == bitwiseAnd)
            {
                // if multiple subarrays have same value of bit wise AND then take the one with maxm length
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}

int longestSubarray(vector<int> &nums)
{
    int n = nums.size();
    // find maxm element as maxm bitwise and would be for this max element
    int maxEle=*max_element(nums.begin(),nums.end());
    // subarray from nums that has maximum possible bitwise AND.
    // k be the maximum value of the bitwise AND of any subarray of nums
    // Return the length of the longest such subarray
    int len = 0;
    int maxLen = 0;

    // generate all subarrays & find subarray having max element in it  
    for (int i = 0; i < n; i++)
    {
        if(nums[i]==maxEle){
            len++;
            maxLen=max(maxLen,len);
        }else{
            len=0;
        }
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {1, 2, 3, 3, 2, 2};
    cout << "\nbrute_force: The length of longest subarray with maxm bitwise ans is: " << brute_force(nums);
    cout << "\nThe length of longest subarray with maxm bitwise ans is: " << longestSubarray(nums);

    return 0;
}