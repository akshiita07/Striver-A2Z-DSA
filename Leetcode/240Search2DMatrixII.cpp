#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: O(m*n)
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

// BETTER: O(m)->taverse thru row*O(log2(n))->perform bin search
bool better(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++)
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
            else if (matrix[i][mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }

    return false;
}

// BINARY SEARCH:       start from 1st row last colm to form inc order
// time- O(m+n)-> for worst case
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int rowPos = 0;                    // 1st row
    int colPos = n - 1;                // last colm
    while (rowPos <m && colPos >= 0) // valid positions
    {
        int element = matrix[rowPos][colPos];
        if (element == target)
        {
            return true;
        }
        else if (element > target)
        {
            // elem is greater so nothing beneath it
            colPos--;
        }
        else
        {
            // element is smaller so nothing in its row
            rowPos++;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target1 = 5;  // T
    int target2 = 20; // F

    cout << "\nBRUTE FORCE: Is " << target1 << " present in matrix: " << brute_force(matrix, target1);
    cout << "\nBRUTE FORCE: Is " << target2 << " present in matrix: " << brute_force(matrix, target2);

    cout << "\nBETTER: Is " << target1 << " present in matrix: " << better(matrix, target1);
    cout << "\nBETTER: Is " << target2 << " present in matrix: " << better(matrix, target2);

    cout << "\nOPTIMAL--> Is " << target1 << " present in matrix: " << searchMatrix(matrix, target1);
    cout << "\nOPTIMAL--> Is " << target2 << " present in matrix: " << searchMatrix(matrix, target2);

    return 0;
}