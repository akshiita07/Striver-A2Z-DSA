// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int cherryPickup(vector<vector<int>> &grid)
{
    // grid: rows x cols
    //  grid[i][j] represents the number of cherries that you can collect from the (i, j)

    // 2 robots at (0,0) & (0, cols - 1)
    //  from (i,j) cell move to (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1)
    //  Return the maximum number of cherries collected by both robots
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, 0)));

    // Base case for the last row
    for (int col1 = 0; col1 < cols; col1++)
    {
        for (int col2 = 0; col2 < cols; col2++)
        {
            if (col1 == col2)
            {
                dp[rows - 1][col1][col2] = grid[rows - 1][col1];
            }
            else
            {
                dp[rows - 1][col1][col2] = grid[rows - 1][col1] + grid[rows - 1][col2];
            }
        }
    }

    // Fill DP from bottom to top
    for (int row = rows - 2; row >= 0; row--)
    {
        for (int col1 = 0; col1 < cols; col1++)
        {
            for (int col2 = 0; col2 < cols; col2++)
            {
                int maxVal = 0;
                for (int d1 = -1; d1 <= 1; d1++)
                {
                    for (int d2 = -1; d2 <= 1; d2++)
                    {
                        int newCol1 = col1 + d1;
                        int newCol2 = col2 + d2;
                        if (newCol1 >= 0 && newCol1 < cols && newCol2 >= 0 && newCol2 < cols)
                        {
                            maxVal = max(maxVal, dp[row + 1][newCol1][newCol2]);
                        }
                    }
                }

                if (col1 == col2)
                {
                    dp[row][col1][col2] = grid[row][col1] + maxVal;
                }
                else
                {
                    dp[row][col1][col2] = grid[row][col1] + grid[row][col2] + maxVal;
                }
            }
        }
    }

    // Start from top-left (0,0) and top-right (0, cols - 1)
    return dp[0][0][cols - 1];
}

int main()
{
    vector<vector<int>> grid = {{3, 1, 1},
                                {2, 5, 1},
                                {1, 5, 5},
                                {2, 1, 1}};
    cout << "Maximum cherries collected = " << cherryPickup(grid);

    return 0;
}