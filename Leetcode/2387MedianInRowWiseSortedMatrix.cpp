#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: O(m*n)->to add elem from 2d to 1d * O(n*m*log2(n*m))->to sort all those 1d array elements
int brute_force(vector<vector<int>> &matrix)
{
    // always odd index given
    int m = matrix.size();
    int n = matrix[0].size();

    // add sorted elements in another vector array
    vector<int> oneDimArray;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            oneDimArray.push_back(matrix[i][j]);
        }
    }

    sort(oneDimArray.begin(), oneDimArray.end());

    // find median from this new formed sorted array
    return oneDimArray[(m * n) / 2];
}

// O(m->for each row*log2(n)->bin search on each colm)
int findNoOfSmallEqual(vector<vector<int>> &matrix, int x)
{
    // find out how many elements are smaller or equal to this x
    int m = matrix.size();
    int n = matrix[0].size();
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        // for each row calculate upper bound
        int low = 0;
        int high = n - 1;
        int upperBound=n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (matrix[i][mid] > x)
            {
                // possible ans but not sure if smallest
                upperBound = mid;
                high = mid - 1;
            }
            else if (matrix[i][mid] <= x)
            {
                // move to right
                low = mid + 1;
            }
        }
        count+=upperBound;
    }
    return count;
}

// O(log2(10^9))
int median(vector<vector<int>> &matrix)
{
    // always odd index given
    int m = matrix.size();
    int n = matrix[0].size();

    // median will be that no. having no of smaller/equal elem greater than m*n/2

    // low:min out of first colm
    int low = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        // in first col
        if (matrix[i][0] < low)
        {
            low = matrix[i][0];
        }
    }

    // low:max out of last colm
    int high = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        // in last col
        if (matrix[i][n - 1] > high)
        {
            high = matrix[i][n - 1];
        }
    }

    int reqd = (m * n) / 2;
    
    // bin search
    while (low <= high)
    {
        int mid = (low + high) / 2;

        int noOfElemSmallOrEqualThanMid = findNoOfSmallEqual(matrix, mid);

        if (noOfElemSmallOrEqualThanMid <= reqd)
        {
            // smaller so i need to check for bigger
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
int main()
{
    vector<vector<int>> matrix = {{1, 5, 7, 9, 11}, {2, 3, 4, 8, 9}, {4, 11, 14, 19, 20}, {6, 10, 22, 99, 100}, {7, 15, 17, 24, 28}};
    cout << "\nBRUTE FORCE: The median is: " << brute_force(matrix);
    cout << "\nThe median is: " << median(matrix);

    return 0;
}