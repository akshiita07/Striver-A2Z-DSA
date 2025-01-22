#include <bits/stdc++.h>
using namespace std;

// time: O(n^2)
// space: O(n^2):visited + O(n^2):queue

void bfs(int row, int colm, vector<vector<int>> &visited, vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // visit it:
    visited[row][colm] = 1;
    queue<pair<int, int>> qu;
    qu.push({row, colm});
    // iterate:
    while (!qu.empty())
    {
        int row = qu.front().first;
        int colm = qu.front().second;
        // remove it:
        qu.pop();
        // neighbours traversal:
        // move to all 8 directions: (row-1,colm-1)(row-1,col)(row-1,col-1)(row,col+1)(row+1,colm+1)(row,colm+1)(row+1,colm-1)(row,colm-1)
        for (int delRow = -1; delRow <= 1; delRow++)
        {
            for (int delColm = -1; delColm <= 1; delColm++)
            {
                int neighbour_row = row + delRow;
                int neighbour_colm = colm + delColm;
                // check validity at boundary: also must be land ie 1 & also not visited
                if (neighbour_row >= 0 && neighbour_row < m && neighbour_colm >= 0 && neighbour_colm < n && grid[neighbour_row][neighbour_colm] == '1' && !visited[neighbour_row][neighbour_colm])
                {
                    // mark as visited
                    visited[neighbour_row][neighbour_colm] = 1;
                    // push in queue:
                    qu.push({neighbour_row, neighbour_colm});
                }
            }
        }
    }
}
void bfs(int row, int colm, vector<vector<int>> &visited, vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // visit it:
    visited[row][colm] = 1;
    queue<pair<int, int>> qu;
    qu.push({row, colm});
    // iterate:
    while (!qu.empty())
    {
        int row = qu.front().first;
        int colm = qu.front().second;
        // remove it:
        qu.pop();
        // neighbours traversal:
        // move to all 4 directions: up,down,left,right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto dir : directions)
        {
            int neighbour_row = row + dir.first;
            int neighbour_colm = colm + dir.second;
            // check validity at boundary: also must be land ie 1 & also not visited
            if (neighbour_row >= 0 && neighbour_row < m && neighbour_colm >= 0 && neighbour_colm < n && grid[neighbour_row][neighbour_colm] == '1' && !visited[neighbour_row][neighbour_colm])
            {
                // mark as visited
                visited[neighbour_row][neighbour_colm] = 1;
                // push in queue:
                qu.push({neighbour_row, neighbour_colm});
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    // m*n
    int m = grid.size();
    int n = grid[0].size();
    // 1:land 0:water
    // return the number of islands
    int count = 0;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for (int row = 0; row < m; row++)
    {
        for (int colm = 0; colm < n; colm++)
        {
            // must not be visited & must be land ie grid value 1
            if (!visited[row][colm] && grid[row][colm] == '1')
            {
                count++;
                bfs(row, colm, visited, grid);
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    cout << "\nNumber of islands= " << numIslands(grid);

    return 0;
}