#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int possibleStringCount(string word, int k)
{
    // trying to type a string of size at least k   ie size>=k
    // Return the total number of possible original strings that Alice might have intended to type
    int n = word.length();
    int cnt = 1;
    vector<int> freq;
    for (int i = 1; i < n; i++)
    {
        if (word[i] == word[i - 1])
        {
            cnt++;
        }
        else
        {
            freq.push_back(cnt);
            cnt = 1;
        }
    }
    freq.push_back(cnt);

    int ans = 1;
    for (auto it : freq)
    {
        ans = static_cast<long long>(ans) * it % mod;
    }

    if (freq.size() >= k)
    {
        return ans;
    }

    vector<int> f(k), g(k, 1);
    f[0] = 1;
    for (int i = 0; i < freq.size(); i++)
    {
        vector<int> f_new(k);
        for (int j = 1; j < k; j++)
        {
            f_new[j] = g[j - 1];
            if (j - freq[i] - 1 >= 0)
            {
                f_new[j] = (f_new[j] - g[j - freq[i] - 1] + mod) % mod;
            }
        }
        vector<int> g_new(k);
        g_new[0] = f_new[0];
        for (int j = 1; j < k; j++)
        {
            g_new[j] = (g_new[j - 1] + f_new[j]) % mod;
        }
        f = move(f_new);
        g = move(g_new);
    }
    return (ans - g[k - 1] + mod) % mod;
}

int main()
{
    string word = "aabbccdd";
    int k = 7;
    cout << "\ntotal number of possible original strings= " << possibleStringCount(word, k);

    return 0;
}