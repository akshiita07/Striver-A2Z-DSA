#include <bits/stdc++.h>
using namespace std;

int getArea(vector<vector<int>> &grid, int x1, int x2, int y1, int y2)
{
    int width = 0;  //-----
    int height = 0; // |
    // find 1 that occurs in row first & where it ends in last row
    int firstRow = INT_MAX;
    int lastRow = INT_MIN;
    // find 1 that occurs in clm first & where it ends in last clm
    int firstColm = INT_MAX;
    int lastColm = INT_MIN;
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
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
    if (lastRow == INT_MIN)
    {
        return 0; // no 1s in this subgrid
    }
    height = lastRow - firstRow + 1;
    width = lastColm - firstColm + 1;

    int area = width * height;
    return area;
}

// min area covering all 1s using 2 rectangles:
int minAreaUsing2Rect(vector<vector<int>> &grid, int x1, int x2, int y1, int y2)
{
    int ans = INT_MAX;
    // check horizontal:
    for (int i = x1; i < x2; i++)
    {
        int a1 = getArea(grid, x1, i, y1, y2);
        int a2 = getArea(grid, i + 1, x2, y1, y2);
        if (a1 != 0 && a2 != 0)
        {
            ans = min(ans, a1 + a2);
        }
    }
    // check vertical:
    for (int j = y1; j < y2; j++)
    {
        int a1 = getArea(grid, x1, x2, y1, j);
        int a2 = getArea(grid, x1, x2, j + 1, y2);
        if (a1 != 0 && a2 != 0)
        {
            ans = min(ans, a1 + a2);
        }
    }
    return ans;
}

int minimumSum(vector<vector<int>> &grid)
{
    // 3 non-overlapping rectangles st all 1s lie within these rectangles
    // Return the minimum possible sum of the area of these rectangles
    int m = grid.size();
    int n = grid[0].size();
    int ans = INT_MAX;
    // check horizontal:
    for (int i = 0; i < m - 1; i++)
    {
        int t1 = getArea(grid, 0, i, 0, n - 1);
        int b2 = minAreaUsing2Rect(grid, i + 1, m - 1, 0, n - 1);
        if (t1 != 0 && b2 != INT_MAX)
        {
            ans = min(ans, t1 + b2);
        }
        int b1 = getArea(grid, i + 1, m - 1, 0, n - 1);
        int t2 = minAreaUsing2Rect(grid, 0, i, 0, n - 1);
        if (b1 != 0 && t2 != INT_MAX)
        {
            ans = min(ans, b1 + t2);
        }
    }
    // check vertical:
    for (int j = 0; j < n - 1; j++)
    {
        int l1 = getArea(grid, 0, m - 1, 0, j);
        int r2 = minAreaUsing2Rect(grid, 0, m - 1, j + 1, n - 1);
        if (l1 != 0 && r2 != INT_MAX)
        {
            ans = min(ans, l1 + r2);
        }
        int r1 = getArea(grid, 0, m - 1, j + 1, n - 1);
        int l2 = minAreaUsing2Rect(grid, 0, m - 1, 0, j);
        if (r1 != 0 && l2 != INT_MAX)
        {
            ans = min(ans, r1 + l2);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid = {};
    cout << "\n minimum possible sum of the area of these rectangles= " << minimumSum(grid);
    return 0;
}