#include <bits/stdc++.h>
using namespace std;

// TIME: O(n)->for loop + O(n) ->adding string using == O(2*n)
// SPACE: O(n)->storing elements in stack
string prefixToPostfix(string exp)
{
    stack<string> st;

    // TIME: O(n)
    // start iterating from back
    int i = exp.length() - 1;
    while (i >= 0)
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
            string elem1 = st.top();
            st.pop();
            string elem2 = st.top();
            st.pop();
            string format = elem1 + elem2 + exp[i];
            st.push(format);
        }
        i--;
    }
    return st.top();
}

int main()
{
    string exp = "/-ab*+def";
    cout << "\nPrefix: " << exp;
    cout << "\nPostfix: " << prefixToPostfix(exp);

    return 0;
}