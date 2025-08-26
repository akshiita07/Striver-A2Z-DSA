#include <bits/stdc++.h>
using namespace std;

int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
{
    int n = dimensions.size();
    // dimensions[i][0] : length of the rectangle i
    // dimensions[i][1] : width of the rectangle i
    int area = INT_MIN;
    float longestDiagonal = FLT_MIN;
    int indexOfLongestDiagonal = -1;
    // Return the area of the rectangle having the longest diagonal
    for (int i = 0; i < n; i++)
    {
        int length = dimensions[i][0];
        int width = dimensions[i][1];
        float currentDiagonal = (float)sqrt(length * length + width * width);
        if (longestDiagonal < currentDiagonal)
        {
            longestDiagonal = max(longestDiagonal, currentDiagonal);
            indexOfLongestDiagonal = i;
            cout << "\nLongest diagonal is: " << longestDiagonal
                 << " for index: " << i;
            area = length * width;
        }
        else if (currentDiagonal == longestDiagonal)
        {
            area = max(area, length * width);
        }
    }
    return area;
}

int main()
{
    vector<vector<int>> dimensions = {};
    cout << "\narea of the rectangle having the longest diagonal= " << areaOfMaxDiagonal(dimensions);

    return 0;
}