#include <bits/stdc++.h>
using namespace std;
// rotate nxn matrix by 90° clockwise

// BRUTE FORCE: TIME:O(n*n)    SPAVE:O(n*n)-->extra space reqd for rotatedMatrix
void rotate_brute(vector<vector<int>> &matrix, int n)
{
    vector<vector<int>> rotatedMatrix = matrix;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotatedMatrix[j][n - i - 1] = matrix[i][j];
        }
    }

    // print matrix
    cout << "\nAfter 90° rotation:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << rotatedMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    int n = matrix.size();
    rotate_brute(matrix, n);

    return 0;
}