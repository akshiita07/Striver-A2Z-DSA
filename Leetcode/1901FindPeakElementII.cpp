#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: O(m*n*4)->worst case AS CHECKING FOR 4 CASES
vector<int> brute_force(vector<vector<int>> &mat)
{
    vector<int> ans(2, -1); // contains index of peak element

    int m = mat.size();
    int n = mat[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0 && mat[i][j] > mat[i - 1][j])
            {
                // check for top elements
                ans[0] = i; // rowIndex
                ans[1] = j; // colIndex
            }
            if (j > 0 && mat[i][j] > mat[i][j - 1])
            {
                // check for left elements
                ans[0] = i; // rowIndex
                ans[1] = j; // colIndex
            }
            if (i < m - 1 && mat[i][j] > mat[i + 1][j])
            {
                // check for neeche elements
                ans[0] = i; // rowIndex
                ans[1] = j; // colIndex
            }
            if (j < n - 1 && mat[i][j] > mat[i][j + 1])
            {
                // check for right elements
                ans[0] = i; // rowIndex
                ans[1] = j; // colIndex
            }
        }
    }

    return ans;
}

// BETTER: O(m*n)->largest element is always a peak element
vector<int> better(vector<vector<int>> &mat)
{
    vector<int> ans(2, -1); // contains index of peak element

    int m = mat.size();
    int n = mat[0].size();
    int max = INT_MIN;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] >= max)
            {
                max = mat[i][j];
                // check for top elements
                ans[0] = i; // rowIndex
                ans[1] = j; // colIndex
            }
        }
    }

    return ans;
}

// BINARY SEARCH: O(log2(n)->bin search on colms*m-->to find max elem from  rows)
// find max out of mid colm & check if it matches cnd
vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    vector<int> ans(2, -1); // contains index of peak element or else -1,-1
    int m = mat.size();
    int n = mat[0].size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // find largest element in the colm of this mid
        int maxElemInCol; // same colm mai find max element
        int maxElemRow;
        int maxElemCol;

        for (int i = low; i < m; i++)
        {
            if (mat[i][mid] > maxElemInCol)
            {
                maxElemInCol = mat[i][mid];
                maxElemRow = i;   // row where max elem is present
                maxElemCol = mid; // colm is same
            }
        }

        int leftElem = (mid - 1 >= 0) ? mat[maxElemRow][maxElemCol - 1] : -1;
        int rightElem = (mid + 1 < n) ? mat[maxElemRow][maxElemCol + 1] : -1;

        // no need to check for top & bottom as we have already taken MAXIMUM out of column
        if (mat[maxElemRow][maxElemCol] > leftElem && mat[maxElemRow][maxElemCol] > rightElem)
        {
            ans[0] = maxElemRow; // rowIndex
            ans[1] = maxElemCol; // colIndex
            break;
        }
        else if (mat[maxElemRow][maxElemCol] < leftElem)
        {
            // left mai koi bada element hai toh delete right half
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> mat1 = {{1, 4}, {3, 2}};
    vector<int> brute_ans1 = brute_force(mat1);
    vector<int> better_ans1 = better(mat1);
    vector<int> ans1 = findPeakGrid(mat1);
    cout << "\nBRUTE FORCE: The index of peak element in mat1 is: " << brute_ans1[0] << " , " << brute_ans1[1];
    cout << "\nBETTER: The index of peak element in mat1 is: " << better_ans1[0] << " , " << better_ans1[1];
    cout << "\nOPTIMAL--> The index of peak element in mat1 is: " << ans1[0] << " , " << ans1[1];

    vector<vector<int>> mat2 = {{10, 20, 15}, {21, 30, 14}, {7, 16, 32}};
    vector<int> brute_ans2 = brute_force(mat2);
    vector<int> ans2 = findPeakGrid(mat2);
    cout << "\nBRUTE FORCE: The index of peak element in mat2 is: " << brute_ans2[0] << " , " << brute_ans2[1];
    cout << "\nOPTIMAL--> The index of peak element in mat2 is: " << ans2[0] << " , " << ans2[1];

    return 0;
}