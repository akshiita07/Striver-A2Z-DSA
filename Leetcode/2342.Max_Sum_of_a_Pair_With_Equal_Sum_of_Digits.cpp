#include <bits/stdc++.h>
using namespace std;

int brute_force(vector<int> &nums)
{
    // choose 2 indices i,j such that i!=j
    // sum of digits of nums[i]=sums of digits of nums[j]
    // return maximum value of nums[i] + nums[j] that satisfy the conditions else return -1 if no such pair
    int n = nums.size();
    int maxSum = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i != j)
            {
                int sum_num1 = 0;
                int sum_num2 = 0;
                int num1 = nums[i];
                int num2 = nums[j];
                // extract digits:
                while (num1 > 0)
                {
                    sum_num1 += (num1 % 10);
                    num1 = num1 / 10;
                }
                while (num2 > 0)
                {
                    sum_num2 += (num2 % 10);
                    num2 = num2 / 10;
                }
                // check if sum is same:
                if (sum_num1 == sum_num2)
                {
                    // satisfies condition:
                    // check sum:
                    int sum = nums[i] + nums[j];
                    maxSum = max(maxSum, sum);
                }
            }
        }
    }
    if (maxSum == INT_MIN)
    {
        return -1;
    }
    return maxSum;
}

int maximumSum(vector<int> &nums)
{
    // hash map: sum of digits->max possible sum with that digits
    unordered_map<int, int> hashMap;
    int maxSum = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int num = nums[i];
        int digit_sum = 0;
        while (num > 0)
        {
            digit_sum += (num % 10);
            num = num / 10;
        }
        // if u find same digit sum:
        if (hashMap.find(digit_sum) != hashMap.end())
        {
            maxSum = max(maxSum, hashMap[digit_sum] + nums[i]);
        }
        hashMap[digit_sum] = max(nums[i], hashMap[digit_sum]);
    }
    if (maxSum == INT_MIN)
    {
        return -1;
    }
    return maxSum;
}

int main()
{
    vector<int> nums = {18, 43, 36, 13, 7}; // 54
    cout << "\nMaximum value of nums[i] + nums[j]= " << maximumSum(nums);
    return 0;
}