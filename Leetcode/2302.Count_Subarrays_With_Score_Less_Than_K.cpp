#include <bits/stdc++.h>
using namespace std;

long long brute_Force(vector<int> &nums, long long k)
{
    // score of array=(sum of array)*(length of array)
    // return number of subarrays of nums whose score<k

    int n = nums.size();
    long long ans = 0;
    // long long sum = accumulate(nums.begin(), nums.end(), 0);
    // long long score = sum * n;
    // cout << "\nScore of subarray is : " << score;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            long long sum = accumulate(nums.begin() + i, nums.begin() + j + 1, 0);
            // now length of subarray is (j-i+1)
            long long score = sum * (j - i + 1);
            cout << "\nScore of subarray is : " << score;
            if (score < k)
            {
                ans++;
            }
        }
    }
    return ans;
}

long long countSubarrays(vector<int> &nums, long long k)
{
    // score of array=(sum of array)*(length of array)
    // return number of subarrays of nums whose score<k
    int n = nums.size();
    long long ans = 0;
    long long sum = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        while (j <= i && sum * (i - j + 1) >= k)
        {
            sum -= nums[j];
            j++;
        }
        ans += (i - j + 1);
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 1, 4, 3, 5};
    long long k = 10;
    cout << "\nCount of Subarrays with score less than k is : " << countSubarrays(nums, k);
    return 0;
}