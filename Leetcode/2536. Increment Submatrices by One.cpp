#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
{
    // n*n matrices filled with 0's
    // query[i] = [row1i, col1i, row2i, col2i]
    // add 1 to top left corner (row1i, col1i) and the bottom right corner (row2i, col2i) entire submatrix
    vector<vector<int>> diff(n + 1, vector<int>(n + 1, 0));

    for (auto &it : queries)
    {
        int r1 = it[0];
        int c1 = it[1];
        int r2 = it[2];
        int c2 = it[3];

        diff[r1][c1] += 1;
        if (c2 + 1 < n)
        {
            diff[r1][c2 + 1] -= 1;
        }
        if (r2 + 1 < n)
        {
            diff[r2 + 1][c1] -= 1;
        }
        if (r2 + 1 < n && c2 + 1 < n)
        {
            diff[r2 + 1][c2 + 1] += 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            diff[i][j] += diff[i][j - 1];
        }
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i < n; i++)
        {
            diff[i][j] += diff[i - 1][j];
        }
    }

    diff.resize(n);
    for (auto &row : diff)
    {
        row.resize(n);
    }

    return diff;
}

int main()
{

    return 0;
}