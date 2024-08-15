#include <bits/stdc++.h>
using namespace std;

// TIME: O(n)->iterating
// SPACE: O(n)->storing inside a stack
bool isValid(string s)
{
    // stack of type char
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        // for all characters:

        // for opening brackets:
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            // push them in stack
            st.push(s[i]);
        }
        // for closing brackets:
        else
        {
            if(st.empty()){
                // agar stack mai no opening bracket
                return false;
            }
            // first check if matches with stack's top most element
            if ((s[i] == ')' && st.top()=='(') || (s[i] == '}' && st.top()=='{') || (s[i] == ']' && st.top()=='['))
            {
                // pop them from stack
                st.pop();
            }else{
                return false;
            }
        }
    }
    // check if stack got empty succesfully
    if(st.empty()){
        return true;
    }else{
        return false;
    }
}

int main()
{
    string s1 = "()[{}()]";
    // cout<<s1.length();
    cout << "\nIs string s1 valid?: " << isValid(s1);
    string s2 = "()[{}(]]";
    cout << "\nIs string s2 valid?: " << isValid(s2);

    return 0;
}