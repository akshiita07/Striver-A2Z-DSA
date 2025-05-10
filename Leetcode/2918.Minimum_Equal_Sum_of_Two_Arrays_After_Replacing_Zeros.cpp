#include <bits/stdc++.h>
using namespace std;

long long minSum(vector<int> &nums1, vector<int> &nums2)
{
    // replace 0s in both arrays with +ve elements such that the sum of both arrays is equal
    // return min sum that can be obtained else -1
    // use 0LL in accumulate as long long to avoid overflow
    long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
    cout << "\nSum of nums1= " << sum1;
    long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);
    cout << "\nSum of nums2= " << sum2;
    int countZero1 = 0;
    int n1 = nums1.size();
    for (int i = 0; i < n1; i++)
    {
        if (nums1[i] == 0)
        {
            countZero1++;
        }
    }
    cout << "\nNumber of zeros in nums1= " << countZero1;
    int countZero2 = 0;
    int n2 = nums2.size();
    for (int i = 0; i < n2; i++)
    {
        if (nums2[i] == 0)
        {
            countZero2++;
        }
    }
    cout << "\nNumber of zeros in nums2= " << countZero2;

    // if already both equal
    if (sum1 == sum2 && countZero1 == 0 && countZero2 == 0)
    {
        return sum1;
    }

    // Replace 0s by 1 and calc new sum:
    sum1 += countZero1;
    sum2 += countZero2;
    cout << "\nAfter replacing sum of nums1= " << sum1;
    cout << "\nAfter replacing sum of nums2= " << sum2;

    // Check max sum from both arrays
    long long maxSum = max(sum1, sum2);
    long long minSum;
    int zerosInOther;
    if (maxSum == sum1)
    {
        cout << "\nMax sum of nums1= " << maxSum;
        zerosInOther = countZero2;
        minSum = sum2;
    }
    else if (maxSum == sum2)
    {
        cout << "\nMax sum of nums2= " << maxSum;
        zerosInOther = countZero1;
        minSum = sum1;
    }
    // check if in min nums remaining zeros present or not
    bool possible = false;
    long long diff = maxSum - minSum;
    cout << "\nDifference between max and min sum= " << diff;
    // Try adding this difference to min nums array: so min nums array must have enough zeros to add it
    if (zerosInOther > 0 || sum1 == sum2)
    {
        possible = true;
    }

    if (possible)
    {
        long long count = maxSum;
        return count;
    }
    return -1;
}

int main()
{
    vector<int> nums1 = {3, 2, 0, 1, 0};
    vector<int> nums2 = {6, 5, 0};
    cout << "\nmin sum that can be obtained= " << minSum(nums1, nums2);

    return 0;
}