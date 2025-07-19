#include <bits/stdc++.h>
using namespace std;

long long minimumDifference(vector<int> &nums)
{
    // nums consists of 3n elements
    // remove subsequence of n elements
    // remaining 2n elements= sumfirst,sumsecond
    // difference in sums:  sumfirst - sumsecond
    // Return the minimum difference possible
    // approach: sum of first n elements<< sum of last n elements
    int n = nums.size() / 3;
    int arrSize = 3 * n;
    // Traverse from left to right to compute prefixMin using a max heap (n smallest elements).
    vector<long long> prefixMin(arrSize, 0);
    priority_queue<int> maxHeap;
    long long sum = 0;
    for (int i = 0; i < arrSize; i++)
    {
        sum += nums[i];
        maxHeap.push(nums[i]);
        if (maxHeap.size() > n)
        {
            sum -= maxHeap.top();
            maxHeap.pop();
        }
        if (maxHeap.size() == n)
        {
            prefixMin[i] = sum;
        }
    }
    // Traverse from right to left to compute suffixMax using a min heap (n largest elements).
    vector<long long> suffixMax(arrSize, 0);
    priority_queue<int, vector<int>, greater<int>> minHeap;
    sum = 0;
    for (int i = arrSize - 1; i >= 0; i--)
    {
        sum += nums[i];
        minHeap.push(nums[i]);
        if (minHeap.size() > n)
        {
            sum -= minHeap.top();
            minHeap.pop();
        }
        if (minHeap.size() == n)
        {
            suffixMax[i] = sum;
        }
    }
    // Finally, try every cut point at position i in [n, 2n].
    long long ans = LLONG_MAX;
    for (int i = n - 1; i < 2 * n; i++)
    {
        ans = min(ans, prefixMin[i] - suffixMax[i + 1]);
    }

    return ans;
}

int main()
{
    vector<int> nums = {7, 9, 5, 8, 1, 3};
    cout << "\nminimum difference possible= " << minimumDifference(nums);

    return 0;
}