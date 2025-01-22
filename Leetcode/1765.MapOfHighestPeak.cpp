#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
{
    int m = isWater.size();
    int n = isWater[0].size();
    //  land cell: isWater[i][j]=0
    //  water cell: isWater[i][j]=1
    // assign HEIGHT to each cell..but water cell height=0
    // Any two adjacent cells must have an absolute height difference of at most 1
    // maximise the maximum possible height of matrix
    vector<vector<int>> height(m, vector<int>(n, -1));
    queue<pair<int, int>> qu;
    // add water cells tp queue & height=0
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isWater[i][j] == 1)
            {
                // is water cell:
                height[i][j] = 0;
                qu.push({i, j}); // push indices
            }
        }
    }
    // Direction vectors for north, south, east, west
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    // BFS:
    while (!qu.empty())
    {
        // get indices of water cell
        auto x = qu.front().first;
        auto y = qu.front().second;
        // remove from queue
        qu.pop();
        for (auto [dx, dy] : directions)
        {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && height[nx][ny] == -1)
            {
                height[nx][ny] = height[x][y] + 1;
                qu.push({nx, ny});
            }
        }
    }
    return height;
}

int main()
{
    vector<vector<int>> isWater = {{0, 1}, {0, 0}};
    vector<vector<int>> ans = highestPeak(isWater);
    for (auto row : ans)
    {
        for (auto it : row)
        {
            cout << it << " ";
        }
        cout << "\n";
    }

    return 0;
}