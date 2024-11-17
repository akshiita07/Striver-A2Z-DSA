#include <bits/stdc++.h>
using namespace std;

int shortestSubarray(vector<int> &nums, int k)
{
    // return length of shortest non-empty subarray of nums with a sum at least k else return -1
    // ie sum>=k
    int n = nums.size();
    vector<long long> prefixArr(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        prefixArr[i + 1] = prefixArr[i] + nums[i];
        // creating prefix array: [0,2,1,3]
    }

    deque<int> dq;
    int minLength = n + 1;

    for (int i = 0; i <= n; i++)
    {
        while (!dq.empty() && (prefixArr[i] - prefixArr[dq.front()]) >= k)
        {
            // 3-1>=3
            // min len=min(4,3-0)=3
            minLength = min(minLength, i - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() && prefixArr[i] <= prefixArr[dq.back()])
        {
            // to maintain the deque in increasing order
            dq.pop_back();
        }
            // when dequeue is empty then add index i in it
        dq.push_back(i);
        // dq:{0,1}
        // dq:{0,2}
        // dq:{2,3}
    }

    if (minLength <= n)
    {
        return minLength;
    }

    return -1;
}

int main()
{
    vector<int> nums = {2, -1, 2};
    int k = 3;
    cout << "\\nLength of shortest subarray with sum atleast " << k << " is: " << shortestSubarray(nums, k);

    return 0;
}