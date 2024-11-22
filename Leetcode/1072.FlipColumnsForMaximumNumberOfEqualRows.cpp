#include <bits/stdc++.h>
using namespace std;

int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    // m*n matrix
    // choose any no of colms & flip its bit 0<->1
    // Return maximum number of rows that have all values equal after some number of flip
    // rows that start with 0s:keep same
    // rows that start with 1s:FLIP
    unordered_map<string, int> hashMap;

    // convert row into string:
    for (int i = 0; i < m; i++)
    {
        string convertedString;
        for (int j = 0; j < n; j++)
        {
            // check for j=0 ie first colm
            if (matrix[i][0] == 1)
            {
                // starts with 1 so flip all bits in string
                if (matrix[i][j] == 1)
                {
                    // after flip
                    convertedString += '0';
                }
                else
                {
                    convertedString += '1';
                }
            }
            else if (matrix[i][0] == 0)
            {
                // starts with 0 so keep as it is
                if (matrix[i][j] == 1)
                {
                    // after flip
                    convertedString += '1';
                }
                else
                {
                    convertedString += '0';
                }
            }
        }
        // push this string in map
        hashMap[convertedString]++;
    }
    // count max:
    int maxCount = INT_MIN;
    for (auto it : hashMap)
    {
        maxCount = max(maxCount, it.second);
    }
    return maxCount;
}

int main()
{
    vector<vector<int>> matrix = {{0, 0, 0}, {0, 0, 1}, {1, 1, 0}};
    // Output: 2
    cout << "\nNo of RQUAL rows after flips are: " << maxEqualRowsAfterFlips(matrix);

    return 0;
}