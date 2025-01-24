#include <bits/stdc++.h>
using namespace std;

// Time: O(n*m):loop + O(m*n):for queue
// Space: O(n*m):queue+O(n*m):visited
int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // 0:empty 1:fresh orange 2:rotten orange
    // every min: fresh orange kept in any 4 diren adjacent to rotten orange will become rotten
    // Return minimum number of minutes that must elapse until no cell has a fresh orange ELSE return -1.
    // add all rotten oranges to a queue:
    queue<pair<pair<int, int>, int>> qu; // stores ((row,colm),time)
    // traverse thru grid & add all rotten oranges in queue along with time=0
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                qu.push({{i, j}, 0});
            }
        }
    }
    int mins = 0;
    // BFS:
    while (!qu.empty())
    {
        int r = qu.front().first.first; //{{r,c},t}
        int c = qu.front().first.second;
        int time = qu.front().second;
        mins = max(mins, time);
        qu.pop();
        // go to neighbours:
        vector<pair<int, int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (auto it : direction)
        {
            int row = r + it.first;
            int colm = c + it.second;

            // if in boundaries && if it is fresh orange && not already rottend =>  then rotten it :
            if (row >= 0 && row < m && colm >= 0 && colm < n && grid[row][colm] == 1)
            {
                qu.push({{row, colm}, time + 1});
                grid[row][colm] = 2;
            }
        }
    }

    // check if no fresh oranges left:
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                return -1; // fresh orange left
            }
        }
    }
    return mins;
}

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << "\nMinimum number of mins until all rotten oranges= " << orangesRotting(grid);

    return 0;
}