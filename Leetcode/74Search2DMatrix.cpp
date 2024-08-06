#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE:
bool brute_force(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
        }
    }

    return false;
}

// BETTER:
bool better(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
        if (matrix[i][n - 1] >= target)
        {
            // may be within this row
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == target)
                {
                    return true;
                }
            }
        }
        else
        {
            // might be on next row
            continue;
        }
    }

    return false;
}

// BINARY SEARCH WITHIN LOOP: O(m)->loop thru rows*O(log2n)->for row binary search
bool searchMatrix1(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] <= target && matrix[i][n - 1] >= target)
        {
            int low = 0;
            int high = n - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (matrix[i][mid] == target)
                {
                    return true;
                }
                else if (matrix[i][mid] < target)
                {
                    // chota hai then check to right
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
    }
    return false;
}

// BINARY SEARCH pt 2:
// flatten array to make a 1d array {hypothetically}
// 1d array size: n*m
// now apply binary saerch on this 1d array so time: O(log2(m*n))
bool searchMatrix_optimal(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int low = 0;    //1st index
    int high = (m*n)-1;       //last index would be m*n-1
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // convert this mid 1d coordinate into a 2d coordinate
        // row: index/n
        // colm: index%n
        int rowNo=mid/n;
        int colNo=mid%n;
        if (matrix[rowNo][colNo] == target)
        {
            return true;
        }
        else if (matrix[rowNo][colNo] < target)
        {
            // chota hai then check to right
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target1 = 3;
    int target2 = 13;

    cout << "\nBRUTE FORCE: Is " << target1 << " present in matrix: " << brute_force(matrix, target1);
    // cout << "\nBRUTE FORCE: Is " << target2 << " present in matrix: " << brute_force(matrix, target2);
    // cout << "\nbetter: Is " << target1 << " present in matrix: " << better(matrix, target1);
    cout << "\nbetter: Is " << target2 << " present in matrix: " << better(matrix, target2);
    cout << "\n1st-> Is " << target1 << " present in matrix: " << searchMatrix1(matrix, target1);
    // cout << "\n1st-> Is " << target2 << " present in matrix: " << searchMatrix1(matrix, target2);
    cout << "\nOPTIMAL--> Is " << target1 << " present in matrix: " << searchMatrix_optimal(matrix, target1);
    cout << "\nOPTIMAL--> Is " << target2 << " present in matrix: " << searchMatrix_optimal(matrix, target2);

    return 0;
}