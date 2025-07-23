#include <bits/stdc++.h>
using namespace std;

int remove(string &s, char first, char second, int points)
{
    stack<char> st;
    int score = 0;
    for (char ch : s)
    {
        if (!st.empty() && st.top() == first && ch == second)
        {
            // foud substring 'first second'
            st.pop();
            score += points;
        }
        else
        {
            st.push(ch);
        }
    }
    // after removing all substrings rebuild string:
    s = "";
    while (!st.empty())
    {
        s += st.top();
        st.pop();
    }
    reverse(s.begin(), s.end());
    return score;
}

int maximumGain(string s, int x, int y)
{
    //  Remove substring "ab" and gain x points
    // Remove substring "ba" and gain y points
    // Return the maximum points you can gain
    int score = 0;
    // will try to always remove substring that gives HIGHER points first
    if (x > y)
    {
        // remove 'ab' first
        score += remove(s, 'a', 'b', x);
        score += remove(s, 'b', 'a', y);
    }
    else
    {
        // remove 'ba' first
        score += remove(s, 'b', 'a', y);
        score += remove(s, 'a', 'b', x);
    }
    return score;
}

int main()
{
    string s = "cdbcbbaaabab";
    int x = 4;
    int y = 5;
    cout << "\nMaximum score from removing substrings= " << maximumGain(s, x, y);

    return 0;
}