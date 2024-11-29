#include <bits/stdc++.h>
using namespace std;

int minimumTime(vector<vector<int>> &grid)
{
    // if no path avilable from right & down from 1st cell return -1:
    if (grid[0][1] > 1 && grid[1][0] > 1)
    {
        return -1;
    }

    int m = grid.size();
    int n = grid[0].size();
    // grid[row][col] represents the minimum time required to be able to visit the cell (row, col)
    // move in 4 directions takes 1 sec: up,down,left,right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    // Return minimum time required in which you can visit the bottom-right cell of the matrix

    // take MIN HEAP to store (time,row,colm)
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    // push current position (0,0) at time 0 in pq
    pq.push({0, 0, 0});

    // a grid to track min amount of time reqd to reach each cell
    vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
    // for first cell time to visit=0
    visited[0][0] = 0;

    while (!pq.empty())
    {
        // tuple<int,int,int> current=pq.top();     or use auto:
        auto [time, row, col] = pq.top();
        pq.pop();

        // if reached bottom right cell then return time taken
        if (row == m - 1 && col == n - 1)
        {
            return time;
        }
        if (time > visited[row][col])
        {
            continue;
        }
    }

    // for all possible directions
    for (int i = 0; i < directions.size(); i++)
    {
        int d_row = directions[i].first;
        int d_col = directions[i].second;
        int new_row = row + d_row;
        int new_col = col + d_col;

        // if within boundaries of matrix:
        if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n)
        {
            // each cell takes 1 sec to mov
            int time_to_wait = max(0, grid[new_row][new_col] - (time + 1));
            if (time_to_wait % 2)
            {
                time_to_wait++;
            }
            int new_time = time_to_wait + time + 1;
            // if can move:
            if (new_time < visited[new_row][new_col])
            {
                visited[new_row][new_col] = new_time;
                pq.push(make_tuple(new_time, new_row, new_col));
            }
        }
    }
}

// if not possible:
return -1;
}

int main()
{
    vector<vector<int>> grid = {{0, 1, 3, 2}, {5, 1, 2, 5}, {4, 3, 8, 6}};
    cout << "\nMin time reqd to reach bottom right cell is: " << minimumTime(grid);

    return 0;
}