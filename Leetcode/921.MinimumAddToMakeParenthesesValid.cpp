#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s)
{
    if (s.length() == 0)
    {
        // empty string
        return 0; // always valid
    }
    stack<int> st;
    int bracketReqd = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            // opening bracket then push in stack
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            // closing brckt then pop from stack
            if (st.empty())
            {
                // if no opening bracket present then:
                st.push('(');
                bracketReqd++;
            }
            st.pop();
        }
    }
    if (!st.empty())
    {
        // add remaining opening brackets
        bracketReqd += st.size();
    }
    return bracketReqd;
}

int main()
{
    string s = "())";
    cout << "\nMin no of paranthesis reqd to make string valid are: " << minAddToMakeValid(s);

    return 0;
}