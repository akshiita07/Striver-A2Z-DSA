#include <bits/stdc++.h>
using namespace std;

// O(n³)
int brute_force(vector<vector<int>> &points)
{
    int n = points.size();
    // points[i] = [xi, yi]
    // Alice at upper left & bob at lower right: no one lese within htis rectangle or line
    // Return the number of pairs of points where you can place Alice and Bob
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x1 = points[i][0];
        int y1 = points[i][1];
        for (int j = 0; j < n; j++)
        {
            // do not check for same point:
            if (i == j)
            {
                continue;
            }
            int x2 = points[j][0];
            int y2 = points[j][1];

            // check if A is upper left or same line:
            if (!(x1 <= x2 && y1 >= y2))
            {
                // if not:
                continue;
            }

            // check if line: vertical
            bool isFine = true;
            for (int k = 0; k < n; k++)
            {
                // do not check for same point:
                if (k == i || k == j)
                {
                    continue;
                }
                int x3 = points[k][0];
                int y3 = points[k][1];
                // check if in bounds
                // if any point lies in between this line then
                // invalid:
                bool insideX = false;
                bool insideY = false;
                if (x3 >= x1 && x3 <= x2)
                {
                    insideX = true;
                }
                if (y3 <= y1 && y3 >= y2)
                {
                    insideY = true;
                }
                if (insideX && insideY)
                {
                    isFine = false;
                    break;
                }
            }

            if (isFine)
            {
                ans++;
            }
        }
    }
    return ans;
}

int numberOfPairs(vector<vector<int>> &points)
{
    int n = points.size();
    // points[i] = [xi, yi]
    // Alice at upper left & bob at lower right: no one lese within htis rectangle or line
    // Return the number of pairs of points where you can place Alice and Bob
    int ans = 0;
    // sort points using custom comparator: x inc & y dec
    sort(points.begin(), points.end(),
         [](const vector<int> &x, const vector<int> &y)
         {
             return x[0] < y[0] || (x[0] == y[0] && x[1] > y[1]);
         });

    for (int i = 0; i < n - 1; i++)
    {
        const auto &pointA = points[i];
        int xMin = pointA[0] - 1;
        int xMax = INT_MAX;
        int yMin = INT_MIN;
        int yMax = pointA[1] + 1;

        for (int j = i + 1; j < n; j++)
        {
            const auto &pointB = points[j];
            if (pointB[0] > xMin && pointB[0] < xMax && pointB[1] > yMin &&
                pointB[1] < yMax)
            {
                ans++;
                xMin = pointB[0];
                yMin = pointB[1];
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> points = {};

    return 0;
}