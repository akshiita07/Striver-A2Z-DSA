#include <bits/stdc++.h>
using namespace std;

// O(n * k²), where k = number of valid column patterns
const int mod = 1e9 + 7;
vector<vector<int>> validPatterns;
unordered_map<int, vector<int>> hashMap;

// all possible colorings of a column of height m:
void generateColors(int m, int curr = 0, int pos = 0, vector<int> colors = {})
{
    if (pos == m)
    {
        validPatterns.push_back(colors);
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        if (pos == 0 || i != colors.back()) // no two adjacent cells having the same color.
        {
            colors.push_back(i);
            generateColors(m, curr * 3 + i, pos + 1, colors);
            colors.pop_back();
        }
    }
}

// convert vector to int
int getKey(vector<int> &colors)
{
    int key = 0;
    for (int i = 0; i < colors.size(); i++)
    {
        key = key * 3 + colors[i];
    }
    return key;
}

int colorTheGrid(int m, int n)
{
    // m*n grid: each cell is initilly white
    // paint each cell R,G,B
    // Return the number of ways to color the grid with no two adjacent cells having the same color.
    validPatterns.clear();
    hashMap.clear();
    generateColors(m);
    int k = validPatterns.size();
    for (int i = 0; i < k; i++)
    {
        int k1 = getKey(validPatterns[i]);
        for (int j = 0; j < k; j++)
        {
            bool flag = true;
            for (int l = 0; l < m; l++)
            {
                if (validPatterns[i][l] == validPatterns[j][l])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                int k2 = getKey(validPatterns[j]);
                hashMap[k1].push_back(k2);
            }
        }
    }
    unordered_map<int, int> dp;
    for (auto it : validPatterns)
    {
        dp[getKey(it)] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        unordered_map<int, int> newDp;
        for (auto &[key, cnt] : dp)
        {
            for (int nextKey : hashMap[key])
            {
                newDp[nextKey] = (newDp[nextKey] + cnt) % mod;
            }
        }
        dp = move(newDp);
    }
    int total = 0;
    for (auto &[key, cnt] : dp)
    {
        total = (total + cnt) % mod;
    }
    return total;
}

int main()
{
    int m = 1;
    int n = 2;
    // ans:6
    cout << "\nnumber of ways to color the grid with no two adjacent cells having the same color= " << colorTheGrid(m, n);

    return 0;
}