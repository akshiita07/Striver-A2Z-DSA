#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int MAX = 1e5 + 5;
long long fact[MAX];
long long invFact[MAX];

long long nCr(int n, int r)
{
    if (r > n)
    {
        return 0;
    }
    return fact[n] * invFact[r] % mod * invFact[n - r] % mod;
}

long long power(long long x, long long y)
{
    long long ans = 1;
    while (y > 0)
    {
        if (y % 2)
        {
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return ans;
}

void computeFactorials()
{
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAX; i++)
    {
        // 4!=4*3*2*1=3!*4
        fact[i] = (fact[i - 1] * i) % mod;
        // compute fermats inverse:
        invFact[i] = power(fact[i], mod - 2);
    }
}

int idealArrays(int n, int maxValue)
{
    // array of length n
    // every arr[i] value lies between 1 and maxValue
    // every arr[i] is divisible by arr[i-1]
    // return no of distinct ideal arrays
    // ideal array is in increasing order
    computeFactorials();
    // in constraints: max value of n=10000
    // so log2(10000)=14
    int maxLen = 14;
    vector<vector<int>> dp(maxValue + 1, vector<int>(maxLen + 1, 0));
    // every no of length 1 is always valid:
    for (int i = 1; i <= maxValue; i++)
    {
        dp[i][1] = 1;
    }
    for (int i = 2; i <= maxLen; i++)
    {
        for (int j = 1; j <= maxValue; j++)
        {
            for (int k = 2 * j; k <= maxValue; k += j)
            {
                dp[k][i] = (dp[k][i] + dp[j][i - 1]) % mod;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= maxValue; i++)
    {
        for (int j = 1; j <= maxLen; j++)
        {
            if (dp[i][j] == 0)
            {
                continue;
            }
            long long totalWays = nCr(n - 1, j - 1);
            ans = (ans + dp[i][j] * totalWays % mod) % mod;
        }
    }
    return ans;
}

int main()
{
    int n = 5;
    int maxValue = 3;
    cout << "\nThe number of ideal arrays is: " << idealArrays(n, maxValue);

    return 0;
}