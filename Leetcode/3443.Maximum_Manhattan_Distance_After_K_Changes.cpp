#include <bits/stdc++.h>
using namespace std;

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
    int x = 0;
    int y = 0;
    // create a direction map:
    map<char, pair<int, int>> direction = {
        {'N', {0, 1}},
        {'S', {0, -1}},
        {'E', {1, 0}},
        {'W', {-1, 0}},
    };

    for (int i = 0; i < n; i++)
    {
        int bestDist = -1;
        char bestMove = s[i];
        // try directions:
        for (auto it : {'N', 'S', 'E', 'W'})
        {
            int new_x = x + direction[it].first;
            int new_y = y + direction[it].second;
            // Calculate Manhattan distance from origin
            int manh_dist = abs(new_x) + abs(new_y);
            if (it == s[i])
            {
                if (manh_dist > bestDist)
                {
                    bestDist = manh_dist;
                    bestMove = it;
                }
            }
            else if (k > 0 && manh_dist > bestDist)
            {
                bestDist = manh_dist;
                bestMove = it;
            }
        }
        x += direction[bestMove].first;
        y += direction[bestMove].second;
        if (bestMove != s[i])
        {
            k--;
        }
        ans = max(ans, abs(x) + abs(y));
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