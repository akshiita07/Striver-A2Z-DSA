#include <bits/stdc++.h>
using namespace std;

long long minTime(vector<int> &skill, vector<int> &mana)
{
    int n = skill.size();
    int m = mana.size();
    // n wizards must brew m potions
    // time taken by the ith wizard on the jth potion is timeij = skill[i] * mana[j]
    // Return the minimum amount of time required for the potions to be brewed properly
    // create f[i] = when wizard i is free
    vector<long long> f(n, 0);

    for (int j = 0; j < m; j++)
    {
        long long x = mana[j];
        long long now = f[0];

        // pass potion through all wizards
        for (int i = 1; i < n; i++)
        {
            now = max(now + skill[i - 1] * x, f[i]);
        }

        // last wizard finishes this potion
        f[n - 1] = now + skill[n - 1] * x;

        // update all earlier wizards in reverse to keep sync
        for (int i = n - 2; i >= 0; i--)
        {
            f[i] = f[i + 1] - skill[i + 1] * x;
        }
    }

    return f[n - 1];
}

int main()
{
    vector<int> skill = {};
    vector<int> mana = {};

    return 0;
}