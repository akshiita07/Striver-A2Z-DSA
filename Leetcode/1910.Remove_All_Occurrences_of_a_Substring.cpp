#include <bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part)
{
    // return string s after removing all occurrences of substring part from left to right:
    // push characters into stack
    stack<int> stk;
    int n = part.length();
    for (auto it : s)
    {
        // push character in stacK
        stk.push(it);
        // check stack top if it matches part:
        if (stk.size() >= n)
        {
            string patternCheck = "";
            for (int i = 0; i < n; i++)
            {
                patternCheck += stk.top();
                stk.pop();
            }
            // check if match:
            reverse(patternCheck.begin(), patternCheck.end());
            if (patternCheck != part)
            {
                // if pattern does not matches then push characters back into stack:
                for (int i = 0; i < n; i++)
                {
                    stk.push(patternCheck[i]);
                }
            }
        }
    }
    // remaining string s is in stack:
    string ans = "";
    while (!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";
    cout << "\nString s after removing all occurrences of substring part= " << removeOccurrences(s, part);
    return 0;
}