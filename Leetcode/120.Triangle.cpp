#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    // if you are on index i on the current row, you may move to either index i or index i + 1 on the next row
    // now move to next row but minimum number:
    int n = triangle.size();
    // start from second last row
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}

int main()
{

    return 0;
}