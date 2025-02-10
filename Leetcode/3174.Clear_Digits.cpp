#include <bits/stdc++.h>
using namespace std;

string clearDigits(string s)
{
    // delete the first digit
    // delete first non digit charcter to this digits left
    // return string after all digits are deleted
    stack<char> stk;
    for (auto it : s)
    {
        if (isdigit(it))
        {
            // remove character:
            if (!stk.empty() && !isdigit(stk.top()))
            {
                stk.pop();
            }
        }
        else
        {
            // push characters in stack:
            stk.push(it);
        }
    }
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
    string s1 = "cb34";
    string s2 = "abc";
    cout << "\n1.String after all digits are deleted= " << clearDigits(s1);
    cout << "\n2.String after all digits are deleted= " << clearDigits(s2);

    return 0;
}