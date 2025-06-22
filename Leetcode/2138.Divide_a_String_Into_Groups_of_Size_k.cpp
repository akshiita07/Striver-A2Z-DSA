#include <bits/stdc++.h>
using namespace std;

vector<string> divideString(string s, int k, char fill)
{
    // partition string s into groups of size k
    // 1st group mai 1st k characters of string s then 2nd group mai next k charcetrs & remaining are filled with fill character
    vector<string> ans;
    int n = s.length();
    for (int i = 0; i < n; i += k)
    {
        string temp = s.substr(i, k);
        while (temp.length() < k)
        {
            // add fill characters:
            temp += fill;
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    string s = "abcdefghij";
    int k = 3;
    char fill = 'x';
    vector<string> ans = divideString(s, k, fill);
    cout << "ANs:\n";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}