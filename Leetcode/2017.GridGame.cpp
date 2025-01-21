#include <bits/stdc++.h>
using namespace std;

long long gridGame(vector<vector<int>> &grid)
{
    // size of grid: 2*n
    // grid[r][c] represents number of points at position (r, c)
    // 2 robots
    // start at (0,0) and want to reach (1, n-1)
    // robot can move from (r, c) to RIGHT (r, c + 1)) or DOWN (r + 1, c))
    // 1st robot: (0,0) to (1,n-1)
    // 2nd robot: (0,0) to (1,n-1)
    //  first robot wants to minimize the number of points collected by the second robot.
    // second robot wants to maximize the number of points it collects
    // return the number of points collected by the second robot
    int n = grid[0].size();
    vector<long long> prefixRow0(n + 1, 0);
    vector<long long> prefixRow1(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefixRow0[i + 1] = prefixRow0[i] + grid[0][i];
        prefixRow1[i + 1] = prefixRow1[i] + grid[1][i];
    }
    long long ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        long long pointsTop = prefixRow0[n] - prefixRow0[i + 1];
        long long pointsBottom = prefixRow1[i];
        long long secondRobotPoints = max(pointsTop, pointsBottom);
        ans = min(ans, secondRobotPoints);
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid = {{2, 5, 4}, {1, 5, 1}};
    cout << "\nNumber of points collected by the second robot= " << gridGame(grid);

    return 0;
}