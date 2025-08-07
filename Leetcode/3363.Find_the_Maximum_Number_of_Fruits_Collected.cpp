// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int maxCollectedFruits(vector<vector<int>> &fruits)
{
    // n*n rooms
    int n = fruits.size();
    // fruits[i][j] represents the number of fruits in the room (i, j)
    // 3 initial positions: (0,0),(0,n-1),(n-1,0)
    // Goal: reach room (n-1,n-1) with exactly n-1 moves
    // if starting room=(0,0)-> (i,j) to (i + 1, j + 1), (i + 1, j), and (i, j + 1)
    // if starting room=(0,n-1)-> (i,j) to (i + 1, j - 1), (i + 1, j), and (i + 1, j + 1)
    // if starting room=(n-1,0)-> (i,j) to (i - 1, j + 1), (i, j + 1), and (i + 1, j + 1)
    // Return the maximum number of fruits the children can collect
    int ans = 0;

    // calculate diagonal number as each child willl cross diagonal atleast once:
    int diagonal = 0;
    for (int i = 0; i < n; i++)
    {
        diagonal += fruits[i][i];
    }
    ans += diagonal;

    auto dp = [&]() -> int
    {
        vector<int> prev(n, INT_MIN);
        vector<int> curr(n, INT_MIN);
        prev[n - 1] = fruits[0][n - 1];
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = max(n - 1 - i, i + 1); j < n; j++)
            {
                int best = prev[j];
                if (j - 1 >= 0)
                {
                    best = max(best, prev[j - 1]);
                }
                if (j + 1 < n)
                {
                    best = max(best, prev[j + 1]);
                }
                curr[j] = best + fruits[i][j];
            }
            swap(prev, curr);
        }
        return prev[n - 1];
    };

    ans += dp();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(fruits[j][i], fruits[i][j]);
        }
    }

    ans += dp();
    return ans;
}

int main()
{
    vector<vector<int>> fruits = {{1, 2, 3, 4},
                                  {5, 6, 8, 7},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16}};
    cout << "\nmaximum number of fruits the children can collect: " << maxCollectedFruits(fruits);

    return 0;
}