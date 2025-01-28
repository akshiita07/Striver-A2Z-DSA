#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &grid, int row, int colm)
{
    int m = grid.size();
    int n = grid[0].size();
    // all possible directions:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int no_of_fish = 0;
    // if within range & water cell:
    if (row >= 0 && row < m && colm >= 0 && colm < n && grid[row][colm] > 0)
    {
        no_of_fish = grid[row][colm];
        // mark as visited:
        grid[row][colm] = 0;
        // move to all directions:
        for (auto &[d_row, d_colm] : directions)
        {
            no_of_fish += dfs(grid, row + d_row, colm + d_colm);
        }
    }
    return no_of_fish;
}

int findMaxFish(vector<vector<int>> &grid)
{
    // m*n matrix:
    int m = grid.size();
    int n = grid[0].size();
    // land cell:grid[r][c] = 0
    // water cell containing grid[r][c] fish, if grid[r][c] > 0.
    // fisher-start at any water cell (r, c)-operations:1. Catch all fish at cell (r, c) 2.Move to any adjacent water cell
    // Return maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.
    // adjacent cell of (r, c): (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c)
    int maxFish = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // if water cell:
            if (grid[i][j] > 0)
            {
                maxFish = max(maxFish, dfs(grid, i, j));
            }
        }
    }

    return maxFish;
}

int main()
{
    vector<vector<int>> grid = {{0, 2, 1, 0}, {4, 0, 0, 3}, {1, 0, 0, 4}, {0, 3, 2, 0}};
    cout << "\nMaximum number of fish the fisher can catch= " << findMaxFish(grid);

    return 0;
}