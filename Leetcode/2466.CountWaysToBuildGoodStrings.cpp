#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int bruteforce(int low, int high, int zero, int one)
{
    // char '0' for zero times
    // char '1' for one times
    // length of good string between low and high
    // RETURN diff no of good strings that can be constructed

    // queue for bfs:
    queue<int> qu;
    qu.push(0); // empty string of length 0
    int ans = 0;
    while (!qu.empty())
    {
        int len = qu.front();
        qu.pop();
        if (len >= low && len <= high)
        {
            ans = (ans + 1) % mod;
        }
        if (len < high)
        {
            qu.push(len + zero); // append zero times
            qu.push(len + one);  // append one times
        }
    }
    return ans;
}
int countGoodStrings(int low, int high, int zero, int one)
{
    // char '0' for zero times
    // char '1' for one times
    // length of good string between low and high
    // RETURN diff no of good strings that can be constructed

    vector<int> dp(high + 1, 0); // dp[i] stores count of good strings of length i
    dp[0] = 1;                   // Base case: There's one way to form a string of length 0 (the empty string)
    int ans = 0;

    for (int i = 0; i <= high; i++)
    {
        if (dp[i] > 0)
        {
            // Append zero
            if (i + zero <= high)
            {
                dp[i + zero] = (dp[i + zero] + dp[i]) % mod;
            }
            // Append one
            if (i + one <= high)
            {
                dp[i + one] = (dp[i + one] + dp[i]) % mod;
            }
        }
        // Add to result if length is within the valid range
        if (i >= low)
        {
            ans = (ans + dp[i]) % mod;
        }
    }

    return ans;
}

int main()
{
    int low = 3;
    int high = 3;
    int zero = 1;
    int one = 1;
    // cout << "\nANs: " << bruteforce(low, high, zero, one);
    cout << "\nANs: " << countGoodStrings(low, high, zero, one);

    return 0;
}