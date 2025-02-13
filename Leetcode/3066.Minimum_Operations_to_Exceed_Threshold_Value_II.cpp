#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums, int k)
{
    int n = nums.size();
    // if n>=2 ie atleast 2 elements: 1 operation: take 2 smallest x,y
    // numbers from nums, remove them & add [min(x, y) * 2 + max(x, y)] in
    // array return minimum number of operations needed so that all elements
    // of the array are greater than or equal to k
    int minNumOfOperations = 0;
    // take min heap priority queue for smallest element removal:
    priority_queue<long, vector<long>, greater<long>> minHeap(nums.begin(), nums.end());
    while (minHeap.top() < k)
    {
        // remove first 2 elements:
        long num1 = minHeap.top();
        minHeap.pop(); // 1st element removed
        long num2 = minHeap.top();
        minHeap.pop(); // 2nd element removed
        // add elem:
        minHeap.push(min(num1, num2) * 2 + max(num1, num2));
        minNumOfOperations++;
    }
    return minNumOfOperations;
}

int main()
{
    vector<int> nums = {2, 11, 10, 1, 3};
    int k = 10;
    cout << "\nMinimum number of operations needed= " << minOperations(nums, k);

    return 0;
}