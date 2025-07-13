#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    // give each child at most one cookie
    // g[i]= greed factor of each child
    // s[j]= size of cookie j
    // assign cookie j to child i if s[j] >= g[i]
    // maximize the number of your content children and output the maximum number
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int n = g.size();
    int m = s.size();
    int i = 0;
    int j = 0;
    int contentChildren = 0;
    while (i < n && j < m)
    {
        if (s[j] >= g[i])
        {
            contentChildren++;
            i++;
            j++;
        }
        else if (s[j] < g[i])
        {
            j++;
        }
    }
    return contentChildren;
}

int main()
{
    vector<int> g = {1, 2};
    vector<int> s = {1, 2, 3};
    cout << "\nnumber of your content children= " << findContentChildren(g, s);

    return 0;
}