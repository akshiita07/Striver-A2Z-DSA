#include <bits/stdc++.h>
using namespace std;

int minimumLength(string s)
{
    // Choose index i in the string st there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
    // Delete the closest character to the left of index i that is equal to s[i].
    // Delete the closest character to the right of index i that is equal to s[i].
    // Return the minimum length of the final string s that you can achieve.

    if (s.length() < 3)
    {
        // no operation possible
        return s.length();
    }
    unordered_map<char, int> hashMap;
    for (int i = 0; i < s.length(); i++)
    {
        hashMap[s[i]]++;
    }
    int minLen = s.length();
    // only characters with count>2 contribute:
    for (auto it : hashMap)
    {
        while (it.second > 2) // ie min 3 count honi chahiye
        {
            minLen -= 2;
            it.second -= 2;
        }
    }
    return minLen;
}

int main()
{
    string s = "abaacbcbb";
    // a:3  b:4     c:2     len=9
    // a:1  b:2     c:2     len=9-2-2=5
    cout << "\nMinimum length of the final string s achievable: " << minimumLength(s);

    return 0;
}