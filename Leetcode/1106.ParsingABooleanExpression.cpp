#include <bits/stdc++.h>
using namespace std;

bool parseBoolExpr(string expression)
{
    // &: and operation
    //  | : or
    // !: not

    stack<char> st;

    // Traverse the expression
    for (char ch : expression)
    {
        if (ch == ')')
        {
            // Evaluate the subexpression when we encounter ')'
            vector<char> operands;

            // Pop characters from the stack until we find the opening '('
            while (!st.empty() && st.top() != '(')
            {
                operands.push_back(st.top());
                st.pop();
            }

            // Pop the '('
            if (!st.empty())
            {
                st.pop(); // Pop the '('
            }

            // Get the operator (&, |, !)
            if (!st.empty())
            {
                char operatorChar = st.top();
                st.pop();

                // Evaluate based on the operator
                bool result;
                if (operatorChar == '&')
                {
                    result = true;
                    for (char operand : operands)
                    {
                        if (operand == 'f')
                        {
                            result = false;
                            break;
                        }
                    }
                }
                else if (operatorChar == '|')
                {
                    result = false;
                    for (char operand : operands)
                    {
                        if (operand == 't')
                        {
                            result = true;
                            break;
                        }
                    }
                }
                else if (operatorChar == '!')
                {
                    result = (operands[0] == 'f');
                }

                // Push the result back to the stack
                st.push(result ? 't' : 'f');
            }
        }
        else if (ch != ',' && ch != '(')
        {
            // Push all relevant characters to the stack
            st.push(ch);
        }
        else if (ch == '(')
        {
            st.push(ch); // Ensure we are pushing the opening parentheses
        }
    }

    // The final result will be on top of the stack
    if (!st.empty() && st.top() == 'f')
    {
        return false;
    }
    else if (!st.empty() && st.top() == 't')
    {
        return true;
    }

    return false; // Default case (if no result found)
}

int main()
{
    string expression = "|(f,f,f,t)";
    cout << "\nThe given expression evalutaes to: " << parseBoolExpr(expression);

    return 0;
}