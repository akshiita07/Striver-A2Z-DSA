#include <bits/stdc++.h>
using namespace std;

long long get(int num)
{
    int i = 1;
    int base = 1;
    long long cnt = 0;
    while (base <= num)
    {
        long long right = min(1LL * base * 2 - 1, 1LL * num);
        long long len = right - base + 1;
        cnt += 1LL * ((i + 1) / 2) * len;
        i++;
        base *= 2;
    }
    return cnt;
}

long long minOperations(vector<vector<int>> &queries)
{
    ll res = 0;
    for (auto &it : queries)
    {
        res += (get(it[1]) - get(it[0] - 1) + 1) / 2;
    }
    return res;
}

int main()
{
    vector<vector<int>> queries = {};

    return 0;
}