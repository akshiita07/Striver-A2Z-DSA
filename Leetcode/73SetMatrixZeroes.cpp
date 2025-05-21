#include <bits/stdc++.h>
using namespace std;

// Brute force: TIME:O(m*n+(m+n))+O(m*n)==O(n^3)
void setZeroes_brute(vector<vector<int>> &matrix)
{
    int m = matrix.size(); // rows
    int n;
    for (auto it : matrix)
    {
        n = it.size(); // columns
    }
    cout << "Number of rows, m= " << m << endl;
    cout << "Number of columns, n= " << n << endl;

    // find pos [m,n] where 0 is present
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                cout << "Index of zero is: [" << i << "," << j << "]" << endl;
                for (int k = 0; k < m; k++) // row
                {
                    if (matrix[k][j] != 0)
                    {
                        matrix[k][j] = -1;
                    }
                }

                for (int k = 0; k < n; k++) // colm
                {
                    if (matrix[i][k] != 0)
                    {
                        matrix[i][k] = -1;
                    }
                }
                // break;
            }
        }
    }

    // convert all -1s to 0s
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // print matrix
    cout << "\nAfter conversion:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Better: TIME:O(m*n+m*n)=O(2mn)       SPACE:0(m+n)->to store row& colm        CHECK IF ROW/COL HAS MIN OF 1 ZERO IN IT
void setZeroes_better(vector<vector<int>> &matrix)
{
    int m = matrix.size(); // rows
    int n;
    for (auto it : matrix)
    {
        n = it.size(); // columns
    }
    cout << "Number of rows, m= " << m << endl;
    cout << "Number of columns, n= " << n << endl;

    // array to see if 0 exists
    vector<int> row(m, 0);
    vector<int> column(n, 0);

    // find pos [m,n] where 0 is present
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark row & colm to 0
                row[i] = 1;
                column[j] = 1;
            }
        }
    }
    // iterate & convert element to 0 if any element's row/column is found to be marked as 1
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i] == 1 || column[j] == 1 && matrix[i][j] != 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // print matrix
    cout << "\nAfter conversion:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// OPTIMAL: TIME:O(m*n+m*n)=O(2mn)       SPACE:0(1)      row/colm check WITHIN D MATRIX
// Modifies matrix in-place
void setZeroes_optimal(vector<vector<int>> &matrix)
{
    int m = matrix.size(); // rows
    int n;
    for (auto it : matrix)
    {
        n = it.size(); // columns
    }
    cout << "Number of rows, m= " << m << endl;
    cout << "Number of columns, n= " << n << endl;

    // take another col0 element
    int col0 = matrix[0][0];
    // row->matrix[_][0]
    // column->matrix[0][_]

    // find pos [m,n] where 0 is present
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark row & colm to 0
                matrix[i][0] = 0;

                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }
    // leave first row & colm
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] != 0) // do only for non zero elements
            {
                // check if row/col is 0
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    // for column first
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 0;
        }
    }
    // for row
    if (col0 == 0)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }

    // print matrix
    cout << "\nAfter conversion:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // jis place pe zero hai uske rows & colm ke all elem=0
    // vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    // Output : [ [ 1, 0, 1 ], [ 0, 0, 0 ], [ 1, 0, 1 ] ]

    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}};
    // setZeroes_brute(matrix);
    // setZeroes_better(matrix);
    setZeroes_optimal(matrix);

    return 0;
}