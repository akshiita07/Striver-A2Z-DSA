#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s)
{
    // number of substrings containing at least one occurrence of all these characters a, b and c
    int n = s.size();
    unordered_map<char, int> hashMap;
    int left = 0;
    int ans = 0;
    for (int right = 0; right < n; right++)
    {
        hashMap[s[right]]++;
        // check if all a,b,c present in window:
        while (hashMap['a'] > 0 && hashMap['b'] > 0 && hashMap['c'] > 0)
        {
            ans += n - right;
            // shrink window from left
            hashMap[s[left]]--;
            left++;
        }
    }
    return ans;
}

int main()
{
    string s = "abcabc";
    cout << "\nAns: " << numberOfSubstrings(s) << endl;

    return 0;
}