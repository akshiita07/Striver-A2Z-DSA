#include <bits/stdc++.h>
using namespace std;

int minimumObstacles(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // 0:empty cell
    // 1:obstacle->can be removed
    // Return minimum number of obstacles to remove to move from upper left corner (0, 0) to the lower right corner (m - 1, n - 1)

    // take disatnce aray & initially all dist as infinity
    vector<vector<int>> distanceArr(m, vector<int>(n, INT_MAX));
    // directions we can move: top,bottom,left,right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    // take dequeue for bfs:
    deque<pair<int, int>> dq;
    // add starting top left cell (0,0) in deque
    dq.push_back({0, 0});
    // distance to starting cell=0
    distanceArr[0][0] = 0;

    // distanceArr = [[0, INF, INF], [INF, INF, INF],[INF, INF, INF]]

    // BFS:
    while (!dq.empty())
    {
        // current:
        pair<int, int> current = dq.front();
        dq.pop_front();
        // row:
        int x = current.first;
        // colm
        int y = current.second;
        // check all 4 possible directions:
        for (int i = 0; i < directions.size(); i++)
        {
            // take both directions
            int dir_x = directions[i].first;
            int dir_y = directions[i].second;
            // move to that (row,col) by adding x,y dist
            int new_x = dir_x + x;
            int new_y = dir_y + y;

            // while within boundaries:
            if (new_x >= 0 && new_y >= 0 && new_x < m && new_y < n)
            {
                // cost=0 if empty & cost=1 if obstacle
                int cost = grid[new_x][new_y];

                // check if we move to this new cell then cost must be min:
                // also checks if already visited
                if (distanceArr[x][y] + cost < distanceArr[new_x][new_y])
                {
                    distanceArr[new_x][new_y] = distanceArr[x][y] + cost;
                    // add cell to deque:
                    if (cost == 0)
                    {
                        // empty cell so push in front to precocess it earlier
                        dq.push_front({new_x, new_y});
                    }
                    else
                    {
                        // cell with obsatcle so push it in back so that first we canc heck all other directions if empty cell available or not
                        dq.push_back({new_x, new_y});
                    }
                }
            }
        }
    }
    // return dist of (0,0) to (m-1,n-1)
    return distanceArr[m - 1][n - 1];
}

int main()
{
    vector<vector<int>> grid = {{0, 1, 1}, {1, 1, 0}, {1, 1, 0}};
    cout << "\nMin no of obstacles to remove are: " << minimumObstacles(grid);

    return 0;
}