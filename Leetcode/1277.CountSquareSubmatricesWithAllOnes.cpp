#include <bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int>> &matrix)
{
    int m = matrix.size();  //rows
    int n = matrix[0].size();       //columns
    int noOfSqOnes = 0;     //ans

    // Iterate through the matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // if the cell is 1
            if (matrix[i][j] == 1)
            {
                // If we're not at the top or left edge, update the cell
                if (i > 0 && j > 0)
                {
                    // cell above
                    // cell toward left
                    // cell diagonally left
                    matrix[i][j] = min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]}) + 1;
                }
                // Add the number of squares ending at (i, j) to the total count
                noOfSqOnes += matrix[i][j];
            }
        }
    }

    return noOfSqOnes;
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    cout << "\nNumber of square matrices of all 1s are: " << countSquares(matrix);

    return 0;
}