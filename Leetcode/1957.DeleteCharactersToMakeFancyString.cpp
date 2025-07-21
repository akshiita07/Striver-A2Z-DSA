#include <bits/stdc++.h>
using namespace std;

string makeFancyString(string s)
{
    // no three consecutive characters are equal
    // delete the minimum possible number of characters from s to make it fancy
    int n = s.length();
    string ans;
    for (int i = 0; i < n; i++)
    {
        // check if it is not duplicate:
        // check if more than 2 characters are available first
        // check 1st prev character
        // now check second prev character:
        if (ans.size() > 2 && ans.back() == s[i] && ans[ans.size() - 2] == s[i])
        {
            continue;
        }
        ans += s[i];
    }
    return ans;
}

int main()
{
    string s = "leeetcode";
    cout << "\nThe fancy string formed is: " << makeFancyString(s);

    return 0;
}