#include <bits/stdc++.h>
using namespace std;

string addOperation(string s, int a)
{
    // only at odd positions:
    for (int i = 1; i < s.size(); i += 2)
    {
        s[i] = ((s[i] - '0' + a) % 10) + '0';
    }
    return s;
}

string rotateOperation(string s, int b)
{
    int n = s.size();
    rotate(s.begin(), s.begin() + (n - b), s.end());
    return s;
}

string findLexSmallestString(string s, int a, int b)
{
    // s of even length with digits 0 to 9
    // add a to all odd indices of s
    // 9 is circled back to 0
    // rotate s to right by b positions
    // Return the lexicographically smallest string by applying these operations
    queue<string> q;
    unordered_set<string> visited;
    string ans = s;

    q.push(s);
    visited.insert(s);

    while (!q.empty())
    {
        string cur = q.front();
        q.pop();

        ans = min(ans, cur);

        // Add
        string added = addOperation(cur, a);
        if (!visited.count(added))
        {
            visited.insert(added);
            q.push(added);
        }

        // Rotate
        string rotated = rotateOperation(cur, b);
        if (!visited.count(rotated))
        {
            visited.insert(rotated);
            q.push(rotated);
        }
    }

    return ans;
}

int main()
{

    return 0;
}