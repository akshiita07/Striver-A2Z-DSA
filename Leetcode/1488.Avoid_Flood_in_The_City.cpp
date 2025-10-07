#include <bits/stdc++.h>
using namespace std;

vector<int> avoidFlood(vector<int> &rains)
{
    // rain over nth lake-> nth lake becomes full of water
    // rain over full lake-> flood
    // rains[i] > 0: rains over the rains[i] lake
    // rains[i] == 0: no rains this day-> choose 1 lake & dry it
    int n = rains.size();
    vector<int> ans(n, 1);
    // ans[i] == -1 if rains[i] > 0.
    // if rains[i] == 0 then ans[i] is the lake you choose to dry in the ith day
    // map each lake to the last day it rained:
    unordered_map<int, int> mp;
    // set of days that can be dried
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (rains[i] == 0)
        {
            s.insert(i);
        }
        else
        {
            int lake = rains[i];
            ans[i] = -1;
            if (mp.count(lake))
            {
                auto it = s.lower_bound(mp[lake]);
                if (it == s.end())
                {
                    return {};
                }
                ans[*it] = lake;
                s.erase(it);
            }
            mp[lake] = i;
        }
    }
    return ans;
}

int main()
{

    return 0;
}