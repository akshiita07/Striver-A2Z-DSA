#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
{
    // m*n matrix
    int m = mat.size();
    int n = mat[0].size();
    // sort diagonals in ascending order
    unordered_map<int, vector<int>> diagonal;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            diagonal[i - j].push_back(mat[i][j]);
        }
    }
    // sort in descending order:
    for (auto &it : diagonal)
    {
        sort(it.second.rbegin(), it.second.rend());
    }
    // pop:in reverse order
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = diagonal[i - j].back();
            diagonal[i - j].pop_back();
        }
    }
    return mat;
}

int main()
{
    vector<vector<int>> mat = {{3, 3, 1, 1}.{2, 2, 1, 2}, {1, 1, 1, 2}};
    // Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
    return 0;
}