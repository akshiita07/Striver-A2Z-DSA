#include <bits/stdc++.h>
using namespace std;

int maxMoves(vector<vector<int>> &grid)
{
    // m x n matrix grid
    // From (row, col), you can move to: (row - 1, col + 1):upper right diagonal, (row, col + 1):next right elements and (row + 1, col + 1):lower right diagonal
    // value of the cell you move to, should be strictly bigger than the value of the current cell.
    // Return the maximum number of moves that you can perform.
    int m = grid.size();    // rows
    int n = grid[0].size(); // colms
    int max_moves = 0;      // track no of moves thatcan be performed

    // dp[i][j] := the maximum number of moves you can perform from (i, j)
    // initialized to zeros
    //  Each cell dp[i][j] will store the maximum number of moves possible
    vector<vector<int>> dp(m, vector<int>(n));

    for (int j = n - 2; j >= 0; j--)
        for (int i = 0; i < m; i++)
        {
            // next right element
            if (grid[i][j + 1] > grid[i][j])
            {
                dp[i][j] = 1 + dp[i][j + 1];
            }
            // upper right diagonal
            if (i > 0 && grid[i - 1][j + 1] > grid[i][j])
            {
                dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j + 1]);
            }
            // lower right diagonal
            if (i + 1 < m && grid[i + 1][j + 1] > grid[i][j])
            {
                dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j + 1]);
            }
        }

    for (int i = 0; i < m; ++i)
    {
        max_moves = max(max_moves, dp[i][0]);
    }

    return max_moves;
}

int main()
{
    vector<vector<int>> grid = {{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};
    cout << "\nMaxm no of moves possible are " << maxMoves(grid);
    return 0;
}