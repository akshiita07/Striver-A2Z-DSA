#include <bits/stdc++.h>
using namespace std;

// alternating cost movement is added to same 3341 problem
// we will add parity: 0 for even: 1s for next move, 1 for odd: 2s for next
// move
int minTimeToReach(vector<vector<int>> &moveTime)
{
    int n = moveTime.size();
    int m = moveTime[0].size();
    // moveTime[i][j] = minimum time in seconds when you can start moving to
    // that room Moving bw adjacent rooms takes one second for one move and
    // two seconds for the next, alternating between the two. Return the
    // minimum time to reach the room (n - 1, m - 1)
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    // directions: up,down,left,right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // {time,x,y,parity}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 0, 0, 0}); // start at {0,0} at time=0 with pairty=0
    dist[0][0] = 0;

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int time = top[0];
        int x = top[1];
        int y = top[2];
        int parity = top[3];
        if (x == n - 1 && y == m - 1) // reached destination
        {
            return time;
        }

        for (auto [dx, dy] : directions)
        {
            int nx = x + dx;
            int ny = y + dy;

            // check if newX,newY is within bounds
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                int cost = (parity & 1) ? 2 : 1;
                int arrival = max(time, moveTime[nx][ny]) + cost;
                if (arrival < dist[nx][ny])
                {
                    dist[nx][ny] = arrival;
                    pq.push({arrival, nx, ny, parity + 1}); // push with new parity
                }
            }
        }
    }

    // destination cell (n-1,m-1)
    return -1;
}

int main()
{
    vector<vector<int>> moveTime = {{0, 4}, {4, 4}};
    cout << "\nMinimum time to reach last room: " << minTimeToReach(moveTime);

    return 0;
}