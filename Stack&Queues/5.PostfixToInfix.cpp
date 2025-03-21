﻿#include <bits/stdc++.h>
using namespace std;

// TIME: O(n)->for loop + O(n) ->adding string using +
// SPACE: O(n)->storing elements in stack
string postfixToInfix(string exp)
{
    stack<string> st;

    // TIME: O(n)
    for (int i = 0; i < exp.length(); i++)
    {
        // operand:push in stack
        if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= '0' && exp[i] <= '9'))
        {
            // typecast into string
            st.push(string(1, exp[i]));
        }
        else
        {
            // operator: pop 2 elements & place operator in between...wrap around () and push inside stack
            string elem2 = st.top();
            st.pop();
            string elem1 = st.top();
            st.pop();
            string format = '(' + elem1 + exp[i] + elem2 + ')';
            st.push(format);
        }
    }
    return st.top();
}

int main()
{
    string exp = "ab-de+f*/";
    cout << "\nPostfix: " << exp;
    cout << "\nInfix: " << postfixToInfix(exp);

    return 0;
}