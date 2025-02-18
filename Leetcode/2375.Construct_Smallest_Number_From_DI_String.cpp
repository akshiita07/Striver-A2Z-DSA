#include <bits/stdc++.h>
using namespace std;

string smallestNumber(string pattern)
{
    int n = pattern.size();
    // pattern contains I:increasing & D:dereasing
    string num = "";
    // num consists of digits from 1 to 9 atMOST once ie 1 or 0 times
    // If pattern[i] == 'I', then num[i] < num[i + 1].
    // If pattern[i] == 'D', then num[i] > num[i + 1].
    // make num lexigraphically smallest
    stack<int> stk;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n + 1; i++)
    {
        // push no in stack:
        stk.push(i);
        // either all nos done or if increasing pattern reqd:
        if (i == n + 1 || pattern[i - 1] == 'I')
        {
            while (!stk.empty())
            {
                // place elements from stack to array:
                ans[i - stk.size()] = stk.top();
                stk.pop();
            }
        }
    }
    // convert ans vector to num string
    for (int i = 0; i < ans.size(); i++)
    {
        num += to_string(ans[i]);
    }
    return num;
}

int main()
{
    string pattern = "IIIDIDDD";
    cout << "\nLexicographically smallest string= " << smallestNumber(pattern);
    return 0;
}