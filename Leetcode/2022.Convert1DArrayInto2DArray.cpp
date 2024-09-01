#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
{
    vector<vector<int>> twoDimenMatrix;
    // construct 2D array of 1d array original of dimesnion m*n

    // check if given no of elem can fit into m*n size:
    int noOfElem = original.size();
    if (m * n < noOfElem)
    {
        // return null
        return {};
    }
    // less no of elem & more elem in matrix
    if (noOfElem<m * n)
    {
        // return null
        return {};
    }

    // otherwise make m rows & n columns
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        vector<int> matrixRow;
        for (int j = 0; j < n; j++)
        {
            // columns
            matrixRow.push_back(original[j + cnt]);
        }
        twoDimenMatrix.push_back(matrixRow);
        // after pushing n elem in row update counter
        cnt += n;
    }

    cout << "\nPrinting the converted 2d matrix:";
    for (auto row : twoDimenMatrix)
    {
        cout << "[";
        for (auto it : row)
        {
            cout << it << " ";
        }
        cout << "]";
    }
    return twoDimenMatrix;
}

int main()
{
    vector<int> original = {1, 2, 3, 4};
    int m = 2;
    int n = 2;
    construct2DArray(original, m, n);

    return 0;
}