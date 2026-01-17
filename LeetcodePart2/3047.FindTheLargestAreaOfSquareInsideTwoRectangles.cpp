#include <bits/stdc++.h>
using namespace std;

long long largestSquareArea(vector<vector<int>> &bottomLeft, vector<vector<int>> &topRight)
{
    // maximum area of a square that can fit inside the intersecting region of at least two rectangles
    long long ans = 0;
    for (int i = 0; i < bottomLeft.size(); i++)
    {
        for (int j = i + 1; j < bottomLeft.size(); j++)
        {
            int left = max((long long)bottomLeft[i][0], (long long)bottomLeft[j][0]);
            int right = min((long long)topRight[i][0], (long long)topRight[j][0]);
            int bottom = max((long long)bottomLeft[i][1], (long long)bottomLeft[j][1]);
            int top = min((long long)topRight[i][1], (long long)topRight[j][1]);

            // check overlapping sq:
            if (left < right && bottom < top)
            {
                long long side = min<long long>(right - left, top - bottom);
                ans = max<long long>(ans, side * side);
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}