#include <bits/stdc++.h>
using namespace std;

// Dijkstra's algorithm with a min-heap
int minTimeToReach(vector<vector<int>> &moveTime)
{
    int n = moveTime.size();
    int m = moveTime[0].size();
    // moveTime[i][j] = minimum time in seconds when you can start moving to that room
    // Start from (0,0) room at time 0 & move to adjacent room (horiz/vert connected) in 1 sec
    // Return the minimum time to reach the room (n - 1, m - 1)
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));    // shortest time to reach each cell
    vector<vector<bool>> visited(n, vector<bool>(m, false)); // visited matrix
    // directions: up,down,left,right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {0, 0}});
    dist[0][0] = 0;

    while (!pq.empty())
    {
        auto [time, pos] = pq.top();
        pq.pop();
        int x = pos.first;
        int y = pos.second;

        if (visited[x][y])
        {
            continue;
        }
        visited[x][y] = true;

        for (auto [dx, dy] : directions)
        {
            int nx = x + dx;
            int ny = y + dy;

            // check if newX,newY is within bounds
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                int arrival = max(time, moveTime[nx][ny]) + 1;
                if (arrival < dist[nx][ny])
                {
                    dist[nx][ny] = arrival;
                    pq.push({arrival, {nx, ny}});
                }
            }
        }
    }

    // destination cell (n-1,m-1)
    return dist[n - 1][m - 1];
}

int main()
{
    vector<vector<int>> moveTime = {{0, 4}, {4, 4}};
    cout << "\nMinimum time to reach last room: " << minTimeToReach(moveTime);
    return 0;
}