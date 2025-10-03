#include <bits/stdc++.h>
using namespace std;

// imp
int trapRainWater(vector<vector<int>> &heightMap)
{
    // return the volume of water it can trap after raining
    int m = heightMap.size();
    int n = heightMap[0].size();

    if (m <= 2 || n <= 2)
    {
        return 0; // Not enough space to trap water
    }

    // Priority queue to store boundary cells with their heights
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Add all boundary cells to the priority queue:
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
            {
                pq.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
    }

    int waterTrapped = 0;
    int maxBoundary = 0;

    while (!pq.empty())
    {
        auto [height, cell] = pq.top();
        pq.pop();
        int x = cell.first;
        int y = cell.second;

        maxBoundary = max(maxBoundary, height);

        // Explore all 4 directions
        for (auto dir : directions)
        {
            int nx = x + dir[0];
            int ny = y + dir[1];

            // Check if the new cell is within bounds and not visited
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny])
            {
                visited[nx][ny] = true;

                // If the current cell is lower than the maxBoundary, water can be trapped
                if (heightMap[nx][ny] < maxBoundary)
                {
                    waterTrapped += maxBoundary - heightMap[nx][ny];
                }

                // Add the new cell to the priority queue
                pq.push({heightMap[nx][ny], {nx, ny}});
            }
        }
    }

    return waterTrapped;
}

int main()
{
    vector<vector<int>> heightMap = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
    cout << "/nVolume of water it can trap after raining= " << trapRainWater(heightMap);

    return 0;
}
