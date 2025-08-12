// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;
vector<vector<int>> dp;

int solve(int num, int n, int x)
{
    if (n == 0)
    {
        return 1; // valid way
    }
    if (pow(num, x) > n)
    {
        return 0; // no further possibilities
    }
    if (dp[num][n] != -1)
    {
        return dp[num][n];
    }

    int take = 0;
    int powerVal = pow(num, x);
    if (powerVal <= n)
    {
        take = solve(num + 1, n - powerVal, x) % MOD;
    }
    int skip = solve(num + 1, n, x) % MOD;

    return dp[num][n] = (take + skip) % MOD;
}

int numberOfWays(int n, int x)
{
    // Return the number of ways n can be expressed as the sum of the xth power of unique positive integers
    dp.assign(n + 1, vector<int>(n + 1, -1));
    return solve(1, n, x);
}

int main()
{
    int n = 10;
    int x = 2;
    cout << "\nAns= " << numberOfWays(n, x);

    return 0;
}