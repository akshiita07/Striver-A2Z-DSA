#include <bits/stdc++.h>
using namespace std;

int precedance(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}

string infixToPostfix(string exp)
{
    stack<char> st;
    string postfix = "";
    for (int i = 0; i < exp.length(); i++)
    {
        if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= '0' && exp[i] <= '9'))
        {
            // operand:add in postfix
            postfix += exp[i];
        }
        else if (exp[i] == ' ') {
            // ignore spaces
                continue;
            }
        else if (exp[i] == '(')
        {
            st.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (st.empty() == false && st.top() != '(')
            {
                // pop
                char el = st.top();
                st.pop();
                postfix += el;
            }
            // pop opening also
            st.pop();
        }
        else
        {
            while (st.empty() == false && precedance(exp[i]) <= precedance(st.top()))
            {
                // stack mai zyada precedance hai
                // else:
                char el = st.top();
                st.pop();
                postfix += el;
            }
            // push
            st.push(exp[i]);
        }
    }
    // remaining
    while (st.empty() == false)
    {
        char el = st.top();
        st.pop();
        postfix += el;
    }
    cout<<"\nThe postfix is: "<<postfix;
    return postfix;
}

int evalPostfix(string postfix)
{
    stack<int> st;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            int elem2 = st.top();
            st.pop();
            int elem1 = st.top();
            st.pop();
            if (postfix[i] == '+')
            {
                st.push(elem1 + elem2);
            }
            else if (postfix[i] == '-')
            {
                st.push(elem1 - elem2);
            }
            else if (postfix[i] == '*')
            {
                st.push(elem1 * elem2);
            }
            else if (postfix[i] == '/')
            {
                st.push(elem1 / elem2);
            }
        }
        else
        {
            // stoi converts string to int
            st.push(postfix[i] - '0');
        }
    }
    return st.top();
}

int calculate(string s)
{
    // check if s does NOT contains any operator then return s itself
    bool isOnlyNumber=true;
    for(int i=0;i<s.length();i++){
        if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/'){
            isOnlyNumber=true;
        }else{
            isOnlyNumber=false;
            break;
        }
    }
    if (isOnlyNumber == true)
    {
        // if it has any parenthesis then remove them
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == ')')
            {
                s.erase(s.begin()+i);
            }
        }
        return stoi(s);
    }
    // convert infix to postfix
    string postfix = infixToPostfix(s);
    // evaluate postfix expression
    int answer = evalPostfix(postfix);
    return answer;
}

int main()
{
    // string s = "(1+(4+5+2)-3)+(6+8)";
    // string s = "1 + 1";
    // string s = "42";
    string s = "14+2";
    cout << "\nAnswer= " << calculate(s);

    return 0;
}