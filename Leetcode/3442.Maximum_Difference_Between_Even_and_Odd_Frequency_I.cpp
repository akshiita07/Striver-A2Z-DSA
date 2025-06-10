#include <bits/stdc++.h>
using namespace std;

int maxDifference(string s)
{
    // find the maximum difference diff = freq(a1) - freq(a2) st a1 has odd freq and a2 has even freq
    unordered_map<char, int> freq;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        freq[s[i]]++;
    }
    // find max odd and min even freq to get max diff
    int maxOdd = INT_MIN;
    int minEven = INT_MAX;
    for (auto it : freq)
    {
        if (it.second % 2 == 0)
        {
            // even:
            minEven = min(minEven, it.second);
        }
        else
        {
            // odd:
            maxOdd = max(maxOdd, it.second);
        }
    }
    return maxOdd - minEven;
}

int main()
{
    string s = "abcabcab";
    cout << "\nMaximum difference: " << maxDifference(s);
    return 0;
}