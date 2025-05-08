#include <bits/stdc++.h>
using namespace std;

// alternating cost movement is added to same 3341 problem
// we will add parity: 0 for even: 1s for next move, 1 for odd: 2s for next move
int minTimeToReach(vector<vector<int>> &moveTime)
{
    int n = moveTime.size();
    int m = moveTime[0].size();
    // moveTime[i][j] = minimum time in seconds when you can start moving to that room
    // Moving bw adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.
    // Return the minimum time to reach the room (n - 1, m - 1)
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2,INT_MAX)));    // shortest time to reach each cell 3d with added parity
    vector<vector<bool>> visited(n, vector<bool>(m, false)); // visited matrix
    // directions: up,down,left,right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // {time,x,y,parity}
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<>> pq;
    pq.push({0, 0,0,0});    //start at {0,0} at time=0 with parity 0
    dist[0][0][0] = 0;

    while (!pq.empty())
    {
        auto [time, x,y,parity] = pq.top();
        pq.pop();
        if(x==n-1 && y=m-1) // reached destination
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
                int cost;
                if(parity==0){
                    cost=1;
                }else if(parity==1){
                    cost=2;
                }
                int arrival = max(time+cost, moveTime[nx][ny]);
                int nextParity=1-parity; // toggle parity
                if (arrival < dist[nx][ny][nextParity])
                {
                    dist[nx][ny][nextParity] = arrival;
                    pq.push({arrival, nx, ny,nextParity}); // push with new parity
                }
            }
        }
    }

    // destination cell (n-1,m-1)
    return min(dist[n - 1][m - 1][0],dist[n - 1][m - 1][1]);
}

int main()
{
    vector<vector<int>> moveTime = {{0, 4}, {4, 4}};
    cout << "\nMinimum time to reach last room: " << minTimeToReach(moveTime);

    return 0;
}