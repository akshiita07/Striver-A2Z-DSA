#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
{
    // n*n matrix
    int n = grid.size();
    // diagonals in bottom left triangle including middle diagonal-> decreasing order sorted
    // diagonals in upper right triangle -> increasing order sorted
    // each diagonal elements have to be sorted in this order
    unordered_map<int, vector<int>> diagonal;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            diagonal[i - j].push_back(grid[i][j]);
        }
    }
    // sort based on position of diagonal:
    for (auto &it : diagonal)
    {
        int index = it.first;
        if (index >= 0)
        {
            // on main or below:
            sort(it.second.rbegin(), it.second.rend());
        }
        else
        {
            sort(it.second.begin(), it.second.end());
        }
    }
    // pop:in reverse order
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = diagonal[i - j].back();
            diagonal[i - j].pop_back();
        }
    }
    return grid;
}

int main()
{
    vector<vector<int>> grid = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};
    // Output: [[8,2,3],[9,6,7],[4,5,1]]
    vector<vector<int>> ans = sortMatrix(grid);
    for (auto row : ans)
    {
        for (auto it : row)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}