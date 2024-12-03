#include <bits/stdc++.h>
using namespace std;

string addSpaces(string s, vector<int> &spaces)
{
    // in spaces add a space in string s before that space index
    int n = s.length();
    int m = spaces.size();
    string ans = "";
    int spacePtr = 0;
    for (int i = 0; i < n; i++)
    {
        // if i am at an index where space needs to be added
        if (spacePtr < m && i == spaces[spacePtr])
        {
            // first add space:
            ans += " ";
            spacePtr++;
        }
        // add other chars:
        ans += s[i];
    }
    return ans;
}

int main()
{
    string s = "LeetcodeHelpsMeLearn";
    vector<int> spaces = {8, 13, 15};
    cout << "\nString after adding spaces is: " << addSpaces(s, spaces);

    return 0;
}