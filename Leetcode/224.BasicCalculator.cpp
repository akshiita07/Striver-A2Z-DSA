﻿#include <bits/stdc++.h>
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
            // for multidigit numbers:
            while (i < exp.length() && isdigit(exp[i]))
            {
                // operand:add in postfix
                postfix += exp[i];
                i++;
            }
            // after addition of number add a space
            postfix += ' ';
            i--;
        }
        else if (exp[i] == ' ')
        {
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
                postfix += ' ';
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
        postfix += ' ';
    }
    cout << "\nThe postfix is: " << postfix;
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
        else if (postfix[i] == ' ')
        {
            // ignore spaces
            continue;
        }
        else
        {
            // operand::
            int num=0;
            while(i<postfix.length() && isdigit(postfix[i])){
                num=num*10+(postfix[i]-'0');
                i++;
            }
            // stoi converts string to int
            st.push(num);
            i--;
        }
    }
    return st.top();
}

int calculate(string s)
{
    // check if s does NOT contains any operator then return s itself
    bool isOnlyNumber = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/')
        {
            isOnlyNumber = true;
        }
        else
        {
            isOnlyNumber = false;
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
                s.erase(s.begin() + i);
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
    string s1 = "(1+(4+5+2)-3)+(6+8)"; // single digit numbers
    cout << "\nAnswer1= " << calculate(s1);
    string s2 = "1 + 1"; // single digit numbers
    cout << "\nAnswer2= " << calculate(s2);
    string s3 = "2147483647"; // only number
    cout << "\nAnswer3= " << calculate(s3);
    string s4 = "(1)"; // multi digit number
    cout << "\nAnswer4= " << calculate(s4);
    string s5 = "14 + 2"; // multi digit number
    cout << "\nAnswer5= " << calculate(s5);

    return 0;
}