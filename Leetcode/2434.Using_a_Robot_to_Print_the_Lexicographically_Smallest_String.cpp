#include <bits/stdc++.h>
using namespace std;

string robotWithString(string s)
{
    // robot holds empty string t
    // apply until s & t both empty: 1. remove first char of s and append to t 2. remove last char of t & write on paper
    // Return lexicographically smallest string that can be written on the paper
    int n = s.length();
    string paper = "";
    stack<char> t; // push from s to t so pop in reverse order
    vector<char> minSuffix(n);
    minSuffix[n - 1] = s[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        minSuffix[i] = min(s[i], minSuffix[i + 1]);
    }
    int i = 0;
    while (i < n)
    {
        t.push(s[i]);
        while (!t.empty() && (i == n - 1 || t.top() <= minSuffix[i + 1]))
        {
            paper += t.top();
            t.pop();
        }
        i++;
    }
    // for leftover characters in stack t:
    while (!t.empty())
    {
        paper += t.top();
        t.pop();
    }
    return paper;
}

int main()
{
    string s = "bac";
    // t="ba" paper="ab"
    // t="c"  paper="abc"
    cout << "\nlexicographically smallest string= " << robotWithString(s);

    return 0;
}