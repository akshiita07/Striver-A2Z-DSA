#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &grid, int row, int colm, int id)
{
    int n = grid.size();
    if (row < 0 || row >= n || colm < 0 || colm >= n || grid[row][colm] != 1)
    {
        // if not in bounds or if not an island:
        return 0;
    }
    // mark the cell with its id
    grid[row][colm] = id;
    int size = 1;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (auto &it : directions)
    {
        int newRow = it.first + row;
        int newColm = it.second + colm;
        size += dfs(grid, newRow, newColm, id);
    }
    return size;
}

int largestIsland(vector<vector<int>> &grid)
{
    // n*n grid
    int n = grid.size();
    //  change at most one 0 to be 1
    // island is a 4-directionally connected group of 1
    // Return size of the largest island in grid
    unordered_map<int, int> islandSize;
    int ans = 0;
    int id = 2; // start id from 2 to distinguish between 0s & 1s
    // identify island & store sizes:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                islandSize[id] = dfs(grid, i, j, id);
                ans = max(ans, islandSize[id]);
                id++;
            }
        }
    }
    // on changing 0 to 1 CHECK:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // check if 0:
            if (grid[i][j] == 0)
            {
                unordered_set<int> neighbours;
                vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for (auto &it : directions)
                {
                    int newRow = it.first + i;
                    int newColm = it.second + j;
                    if (newRow >= 0 && newRow < n && newColm >= 0 && newColm < n && grid[newRow][newColm] > 1)
                    {
                        neighbours.insert(grid[newRow][newColm]);
                    }
                }
                // convert this 0 to 1 & calculate new size:
                int newSize = 1;
                for (auto it : neighbours)
                {
                    newSize += islandSize[it];
                }
                ans = max(ans, newSize);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid = {{1, 0}, {0, 1}};
    cout << "\nsize of the largest island in grid= " << largestIsland(grid);
    return 0;
}