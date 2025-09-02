#include <bits/stdc++.h>
using namespace std;

int numberOfPairs(vector<vector<int>> &points)
{
    // points[i] = [xi, yi]
    int n = points.size();
    // Count the number of pairs of points (A, B) st A is on the upper left
    // side of B & no otherpoints on rectangle/line they make xA (left)< xB
    // and yA (upper)> yB
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

int main()
{
    vector<vector<int>> points = {{6, 2}, {4, 4}, {2, 6}};
    cout << "\nAns= " << numberOfPairs(points);
    return 0;
}