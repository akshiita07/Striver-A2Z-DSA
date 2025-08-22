#include <bits/stdc++.h>
using namespace std;

int minimumArea(vector<vector<int>> &grid)
{
    // return minimum possible area of rectangle=width*height st all 1s lie
    // within this rectangle
    int m = grid.size();
    int n = grid[0].size();
    int width = 0;  //-----
    int height = 0; // |
    // find 1 that occurs in row first & where it ends in last row
    int firstRow = INT_MAX;
    int lastRow = INT_MIN;
    // find 1 that occurs in clm first & where it ends in last clm
    int firstColm = INT_MAX;
    int lastColm = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                firstRow = min(firstRow, i);
                lastRow = max(lastRow, i);
                firstColm = min(firstColm, j);
                lastColm = max(lastColm, j);
            }
        }
    }
    height = lastRow - firstRow + 1;
    width = lastColm - firstColm + 1;

    int area = width * height;
    return area;
}

int main()
{
    vector<vector<int>> grid = {{1, 0}, {0, 0}};
    cout << "\nAns= " << minimumArea(grid);

    return 0;
}