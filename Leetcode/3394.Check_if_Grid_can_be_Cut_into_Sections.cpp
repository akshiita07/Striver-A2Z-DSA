#include <bits/stdc++.h>
using namespace std;

int isPossible(vector<pair<int, int>> &positions)
{
    int count = 0;
    int prevEnd = 0;
    sort(positions.begin(), positions.end());
    for (const auto &[start, end] : positions)
    {
        if (start < prevEnd)
        {
            prevEnd = max(prevEnd, end);
        }
        else
        {
            prevEnd = end;
            count++;
        }
    }
    return count;
}
bool checkValidCuts(int n, vector<vector<int>> &rectangles)
{
    // n*n grid
    // rectangles[i]= [startx, starty, endx, endy]
    // (startx, starty): bottom-left corner
    // (endx, endy): The top-right corner
    // determine if possible to make either 2 horizontal/vertical cuts on the grid st:Each of the three resulting sections formed by the cuts contains at least one rectangle,Every rectangle belongs to exactly one section.
    // Return true if such cuts can be made; otherwise, return false.
    vector<pair<int, int>> xSet, ySet;
    for (auto &it : rectangles)
    {
        // insert startx and endx in x set
        xSet.push_back({it[0], it[2]});
        // insert starty and endy in y set
        ySet.push_back({it[1], it[3]});
    }
    // check for both horizontal and vertical cuts
    return max(isPossible(xSet), isPossible(ySet)) >= 3;
}

int main()
{
    int n = 5; // ie 5*5 grid
    vector<vector<int>> rectangles = {{1, 0, 5, 2}, {0, 2, 2, 4}, {3, 2, 5, 3}, {0, 4, 4, 5}};
    cout << "\ncan cuts can be made= " << checkValidCuts(n, rectangles);

    return 0;
}