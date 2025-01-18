#include <bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>> &grid)
{
    // m*n grid
    // grid[i][j]
    // 1:right: [i][j+1]
    // 2:left:  [i][j-1]
    // 3:lower: [i+1][j]
    // 4:upper: [i1][j]
    // start from (0,0) to (m-1,n-1)
    int m = grid.size();
    int n = grid[0].size();

    // Directions corresponding to 1: right, 2: left, 3: down, 4: up
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Cost array to store minimum cost to reach each cell
    vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
    deque<pair<int, int>> dq; // deque for 0-1 BFS

    dq.push_back({0, 0});
    cost[0][0] = 0;

    while (!dq.empty())
    {
        auto [x, y] = dq.front();
        dq.pop_front();

        // Check all 4 directions
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            int newCost = cost[x][y] + (grid[x][y] != i + 1); // Add cost if direction changes

            if (nx >= 0 && ny >= 0 && nx < m && ny < n && newCost < cost[nx][ny])
            {
                cost[nx][ny] = newCost;
                // Push to deque based on cost
                if (grid[x][y] == i + 1)
                {
                    dq.push_front({nx, ny}); // No cost for this move
                }
                else
                {
                    dq.push_back({nx, ny}); // Cost added for this move
                }
            }
        }
    }

    return cost[m - 1][n - 1];
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}};
    cout << "\nMinimum cost to make the grid have at least one valid path: " << minCost(grid);

    return 0;
}