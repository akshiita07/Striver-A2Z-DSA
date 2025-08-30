#include <bits/stdc++.h>
using namespace std;

bool checkValid(vector<vector<int>> &matrix)
{
    // n x n matrix
    // valid: each row & clm has numbers from 1 to n
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        set<int> uniqueElementsRow;
        set<int> uniqueElementsClm;
        for (int j = 0; j < n; j++)
        {
            uniqueElementsRow.insert(matrix[i][j]);
            uniqueElementsClm.insert(matrix[j][i]);
        }
        if (uniqueElementsRow.size() != n || uniqueElementsClm.size() != n)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> matrix = {};
    cout << "\nvalid= " << checkValid(matrix);

    return 0;
}