#include <bits/stdc++.h>
using namespace std;

int priority(char ch)      //TIME:O(1)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '^')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}
// TIME: O(n)->while+O(n)->while loop
// SPACE: O(n):stack + O(n):string to return ans
string infixToPostfix(string exp)
{
    string postfix = "";
    stack<char> st; // stores operators so type:char

    // loop thru given expression
    for (int i = 0; i < exp.length(); i++)      //TIME:O(n)
    {
        if (exp[i] == '(')      //TIME:O(1)
        {
            // for opening bracket simply push in stack:
            st.push(exp[i]);
        }
        // if operand: push in postfix
        else if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= '0' && exp[i] <= '9'))      //TIME:O(1)
        {
            postfix += exp[i];
        }
        else if (exp[i] == ')')      //TIME:O(n):worst case
        {
            // if closing bracket then pop all elements until ( is found
            while (st.top() != '(' && st.empty()==false)
            {
                char elem = st.top();
                st.pop();
                postfix += elem;
            }
            // when ( is found then pop it also
            st.pop();
        }
        else       //TIME:O(n):worst case
        {
            // if operator +,-,*,/->push in stack
            // exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^' ||
            while (st.empty()==false && priority(exp[i]) < priority(st.top()))  //not adding equal!!
            {
                // smaller priority so pop
                char elem = st.top();
                st.pop();
                postfix += elem;
            }
            // greater priority so simply push
            st.push(exp[i]);
        }
    }

    // if eleme r remaiing in stack then pop them
    while (st.empty()==false)       //TIME:O(n):worst case
    {
        char elem = st.top();
        st.pop();
        postfix += elem;
    }

    return postfix;
}

string reverseString(string exp){
    string reversedString="";
    stack<char> st;
    for(int i=0;i<exp.length();i++){
        st.push(exp[i]);
    }
    while(st.empty()==false){
        reversedString+=st.top();
        st.pop();
    }
    return reversedString;
}

// TIME: O(3n)
// SPACE: O(n):stack + O(n):string to return ans
string infixToPrefix(string exp)
{
    // step1: reverse exp
    exp=reverseString(exp);         //TIME:O(n)
    // step2: convert ( to ) and vice vers
    for(int i=0;i<exp.length();i++){
        if(exp[i]=='('){
            exp[i]=')';
        }
        else if(exp[i]==')'){
            exp[i]='(';
        }
    }
    // step3: convert exp to postfix
    string postfix = infixToPostfix(exp);   //modified one           //TIME:O(n)
    // step4: reverse this to get ans
    string prefix=reverseString(postfix);            //TIME:O(n)

    return prefix;
}

int main()
{
    string exp = "(a+b)*c-d+f";
    cout << "\nInfix: " << exp;
    cout << "\nPrefix: " << infixToPrefix(exp);

    return 0;
}