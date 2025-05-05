#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
// return the number of ways to tile an 2 x n board
// domino: 2 shaped
// tromino: 3 shaped

// vertical domino covers 2x1 (2rows, 1 column) so no of columns left = n-1
// 1 horizontal domino covers 1x2 (1row, 2 columns) so no of columns left = n-2
// 2 horizontal domino covers 2x2
// L shaped tromino: 2types of placements possible: .. or  -
//                                                  .     --
// so it takes up 3 columns so no of colms left = n-3
// Exponential time: O(3^n) as 3 recursive branches possible
// Space: O(n) for recursive stack
int brute_Force(int n)
{
    if (n == 0)
    {
        // empty board
        return 1;
    }
    if (n == 1)
    {
        // tile 2x1 board
        // one vertical domino
        return 1;
    }
    if (n == 2)
    {
        // tile 2x2 board:
        // 2 horiz dominos OR 2 vert dominos
        return 2;
    }
    // recursion:
    // option1: vertical domino
    int ans = brute_Force(n - 1);
    // option2: 2horizontal domino
    int ans = (ans + brute_Force(n - 2)) % mod;
    // option3: 2 unique placemnet of tromino:
    for (int i = 0; i <= n - 3; i++)
    {
        // place tromino at i and i+1, i+2
        ans = (ans + 2LL * brute_Force(i) % mod) % mod;
    }
}

// Time: O(n) as single loop
// Space: O(n) for dp table
int numTilings(int n)
{
    // dp[i] table denotes no of ways to tile a 2xi board
    if (n == 0)
    {
        return 1;
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // empty board
    if (n >= 1)
    {
        dp[1] = 1; // 2x1 board
    }
    if (n >= 2)
    {
        dp[2] = 2; // 2x2 board
    }
    // let pre denote no of ways to tile 2xn board with 1 square missing in tromino case:
    long long sum = 0;
    for (int i = 3; i <= n; i++)
    {
        sum = (sum + dp[i - 3]) % mod;
        dp[i] = (dp[i - 1] + dp[i - 2] % mod + 2LL * sum % mod) % mod;
    }
    return dp[n];
}

int main()
{
    int n = 3;
    cout << "\nbrute_Force Number of ways to tile a 2 x " << n << " board: " << brute_Force(n);
    cout << "\nNumber of ways to tile a 2 x " << n << " board: " << numTilings(n);

    return 0;
}