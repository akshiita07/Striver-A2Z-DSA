#include <bits/stdc++.h>
using namespace std;

int count(int a, int b, int change)
{
    return abs(a - b) + change * 2;
}

int maxDistance(string s, int k)
{
    // N,S,E,W directions given in string s
    // Find maximum Manhattan distance from the origin (0,0) that can be achieved at any time while performing the movements in order
    // Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|
    // for north: (x, y) -> (x, y + 1)
    // for south: (x, y) -> (x, y - 1)
    // for East: (x, y) -> (x + 1, y)
    // for West: (x, y) -> (x-1, y)
    int n = s.length();
    int ans = INT_MIN;
    int north = 0;
    int south = 0;
    int east = 0;
    int west = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'N')
        {
            north++;
        }
        else if (s[i] == 'S')
        {
            south++;
        }
        else if (s[i] == 'E')
        {
            east++;
        }
        else if (s[i] == 'W')
        {
            west++;
        }
        int change_vertical = min(min(north, south), k);
        int change_horizontal = min(min(east, west), k - change_vertical);
        int vert = count(north, south, change_vertical);
        int horiz = count(east, west, change_horizontal);
        ans = max(ans, vert + horiz);
    }
    return ans;
}

int main()
{
    string s = "NWSE";
    int k = 1;
    cout << "\nMaximum Manhattan Distance: " << maxDistance(s, k);

    return 0;
}