#include <bits/stdc++.h>
using namespace std;

int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    // arr & mat contain all the integers in the range [1, m * n]
    // for each i in arr[i] paint cell in mat containing arr[i]
    // return smallest i where a row/colm is completely filled in mat
    // length of array: m*n
    // map each element in mat with its [row,col]
    unordered_map<int, pair<int, int>> hashMap;
    // store matrix in this hashMap:
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            hashMap[mat[i][j]] = {i, j};
        }
    }
    // 2 vectors to maintain no of painted rows & no of painted columns:
    vector<int> paintedRows(m, 0);
    vector<int> paintedColumns(n, 0);
    // traverse array:
    for (int i = 0; i < m * n; i++)
    {
        int row = hashMap[arr[i]].first;
        int column = hashMap[arr[i]].second;
        paintedRows[row]++;
        paintedColumns[column]++;
        // check if either row/colm filled:
        // row is completely painted when all columns are painted
        // colm is completely painted when all rows are painted
        if (paintedRows[row] == n || paintedColumns[column] == m)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 3, 4, 2};
    vector<vector<int>> mat = {{1, 4}, {2, 3}};
    cout << "\nSmallest i where row/colm is completely filled in mat= " << firstCompleteIndex(arr, mat);

    return 0;
}