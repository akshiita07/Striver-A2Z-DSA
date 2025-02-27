#include <bits/stdc++.h>
using namespace std;

int lenLongestFibSubseq(vector<int> &arr)
{
    // fib: arr[i+2]=arr[i]+arr[i+1]
    int n = arr.size();
    unordered_map<int, int> hashMap;
    // fill hashMap:
    for (int i = 0; i < n; i++)
    {
        hashMap[arr[i]] = i;
    }
    // dp:
    vector<vector<int>> dp(n, vector<int>(n, 2));
    int longestLen = 0;

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < j; i++)
        {
            // if arr[k]+arr[i]=arr[j] arr[k] is in hashmap then we can update length
            int target = arr[j] - arr[i]; // elem to find in hashmap
            if (target < arr[i] && hashMap.find(target) != hashMap.end())
            {
                dp[i][j] = dp[hashMap[target]][i] + 1;
                longestLen = max(longestLen, dp[i][j]);
            }
        }
    }

    if (longestLen >= 3)
    {
        return longestLen;
    }
    return 0; // it says fib series must have elem>=3 else 0
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << "\nLength of longest fib series= " << lenLongestFibSubseq(arr);

    return 0;
}