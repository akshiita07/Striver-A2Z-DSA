#include <bits/stdc++.h>
using namespace std;

// O(n²)
string brute_force(string s)
{
    // Delete the leftmost '*' and the smallest non-'*' character to its left
    // Return the lexicographically smallest resulting string after removing all '*' characters
    int n = s.size();
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            // remove * & smallest leftmost:
            if (!ans.empty())
            {
                int pos = ans.size() - 1;
                for (int i = ans.size() - 1; i >= 0; i--)
                {
                    // bind smallest char using pos:
                    if (ans[i] < ans[pos])
                    {
                        pos = i;
                    }
                }
                // remove it
                ans.erase(ans.begin() + pos);
            }
        }
        else
        {
            ans += s[i];
        }
    }
    return ans;
}

// O(n)
string clearStars(string s)
{
    // Delete the leftmost '*' and the smallest non-'*' character to its left
    // Return the lexicographically smallest resulting string after removing all '*' characters
    int n = s.size();
    vector<stack<int>> count(26);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            for (int j = 0; j < 26; j++)
            {
                if (!count[j].empty())
                {
                    s[count[j].top()] = '*';
                    count[j].pop();
                    break;
                }
            }
        }
        else
        {
            count[s[i] - 'a'].push(i);
        }
    }

    string ans;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '*')
        {
            ans.push_back(s[i]);
        }
    }
    return ans;
}

int main()
{
    string s = "aaba*";
    cout << "\nbrute_force: lexicographically smallest resulting string= " << brute_force(s);
    cout << "\nlexicographically smallest resulting string= " << clearStars(s);
    return 0;
}