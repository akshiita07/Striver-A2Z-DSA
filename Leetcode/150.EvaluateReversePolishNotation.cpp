#include <bits/stdc++.h>
using namespace std;

// 48 to 57 is ascii value of "0" to "9"
int evalRPN(vector<string> &tokens)
{
    stack<int> st;
    // loop thru array of tokens
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
            // if operator then pop 2 elements & add oepration in between
            int ele2 = st.top();
            st.pop();
            int ele1 = st.top();
            st.pop();
            if (tokens[i] == "+")
            {
                st.push(ele1 + ele2);
            }
            else if (tokens[i] == "-")
            {
                st.push(ele1 - ele2);
            }
            else if (tokens[i] == "*")
            {
                st.push(ele1 * ele2);
            }
            else if (tokens[i] == "/")
            {
                st.push(ele1 / ele2);
            }
        }
        else
        {
            // push inside stack
            st.push(stoi(tokens[i])); // typecast as int
        }
    }

    return st.top();
}

int main()
{
    // GIVEN REVERSE POLISH NOTATION: POSTFIX tokensRESSION-> EVALUATE IT
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << "\nAfter evaluation ans= " << evalRPN(tokens1); // 9

    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << "\nAfter evaluation ans= " << evalRPN(tokens2); // 6

    return 0;
}