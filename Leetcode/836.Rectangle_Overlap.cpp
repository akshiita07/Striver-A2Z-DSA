#include <bits/stdc++.h>
using namespace std;

bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
{
    // vector<int> [x1, y1, x2, y2]
    // bottom left (x1, y1) , top right (x2, y2)
    // rec1
    int x1a = rec1[0];
    int y1a = rec1[1];
    int x2a = rec1[2];
    int y2a = rec1[3];
    // rec2
    int x1b = rec2[0];
    int y1b = rec2[1];
    int x2b = rec2[2];
    int y2b = rec2[3];
    // if 1 rectangle is left to other
    if (x1a >= x2b || x1b >= x2a)
    {
        return false;
    }
    // if 1 rectangle is on top of other
    if (y1a >= y2b || y1b >= y2a)
    {
        return false;
    }
    // yes overlap:
    return true;
}

int main()
{
    vector<int> rec1 = {};
    vector<int> rec2 = {};

    return 0;
}