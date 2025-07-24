#include <bits/stdc++.h>
using namespace std;

int calc(int part1, int part2, int part3)
{
    return max(part1, max(part2, part3)) - min(part1, min(part2, part3));
}

int minimumScore(vector<int> &nums, vector<vector<int>> &edges)
{
    int n = nums.size();
    vector<vector<int>> e(n);
    for (auto &it : edges)
    {
        e[it[0]].push_back(it[1]);
        e[it[1]].push_back(it[0]);
    }

    int sum = 0;
    for (auto it : nums)
    {
        sum ^= it;
    }

    int res = INT_MAX;
    function<int(int, int, int, int)> dfs2 = [&](int x, int f, int oth, int anc)
    {
        int son = nums[x];
        for (auto &y : e[x])
        {
            if (y == f)
            {
                continue;
            }
            son ^= dfs2(y, x, oth, anc);
        }
        if (f == anc)
        {
            return son;
        }
        res = min(res, calc(oth, son, sum ^ oth ^ son));
        return son;
    };

    function<int(int, int)> dfs = [&](int x, int f)
    {
        int son = nums[x];
        for (auto &y : e[x])
        {
            if (y == f)
            {
                continue;
            }
            son ^= dfs(y, x);
        }

        for (auto &y : e[x])
        {
            if (y == f)
            {
                dfs2(y, x, son, x);
            }
        }
        return son;
    };

    dfs(0, -1);
    return res;
}

int main()
{
    vector<int> nums = {1, 5, 5, 4, 11};
    vector < vector<int> edges = {{0, 1}, {1, 2}, {1, 3}, {3, 4}};

    return 0;
}