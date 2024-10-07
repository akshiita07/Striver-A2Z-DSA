#include <bits/stdc++.h>
using namespace std;

int minLength(string s)
{
    stack<char> st;
    // repeatedy check if AB or CD occurrs simultaneously & remove it:
    for (char ch : s)
    {
        if (!st.empty() && ((st.top() == 'A' && ch == 'B') || (st.top() == 'C' && ch == 'D')))
        {
            st.pop();
        }
        else
        {
            st.push(ch);
        }
    }
    return st.size();
}

int main()
{
    string s = "ABFCACDB";
    cout << "\nAfter removing AB and CD we get length= " << minLength(s);

    return 0;
}