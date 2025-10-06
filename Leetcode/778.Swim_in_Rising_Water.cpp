#include <bits/stdc++.h>
using namespace std;

int swimInWater(vector<vector<int>> &grid)
{
    int n = grid.size();
    // grid[i][j] : elevation at that point (i, j)
    // at time t-> water level=t
    // if cells have elevation<t then they submerge
    // Return minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0)
    vector<vector<int>> visited(n, vector<int>(n, 0));
    // priority queue for elevation:
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    pq.push({grid[0][0], 0, 0});
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int ans = 0;
    while (!pq.empty())
    {
        auto current = pq.top();
        pq.pop();
        int t = current[0];
        int x = current[1];
        int y = current[2];

        if (visited[x][y])
        {
            continue;
        }
        visited[x][y] = 1;
        ans = max(ans, t);
        if (x == n - 1 && y == n - 1)
        {
            return ans;
        }
        for (auto &it : directions)
        {
            int new_x = x + it[0];
            int new_y = y + it[1];
            if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < n && !visited[new_x][new_y])
            {
                pq.push({grid[new_x][new_y], new_x, new_y});
            }
        }
    }
    return -1;
}

int main()
{

    return 0;
}