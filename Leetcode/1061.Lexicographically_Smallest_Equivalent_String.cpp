#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int a)
{
    if (a != parent[a])
    {
        parent[a] = find(parent[a]);
    }
    return parent[a];
}

void findUnion(int a, int b)
{
    int parent_a = find(a);
    int parent_b = find(b);
    if (parent_a == parent_b)
    {
        return;
    }
    if (parent_a < parent_b)
    {
        parent[parent_b] = parent_a;
    }
    else
    {
        parent[parent_a] = parent_b;
    }
}

string smallestEquivalentString(string s1, string s2, string baseStr)
{
    // s1 length == s2.length
    int n = s1.length();
    parent.resize(26);
    for (int i = 0; i < 26; i++)
    {
        parent[i] = i;
    }
    // s1[i] and s2[i] are equivalent characters ie reflexive, symmetric and transitive
    // Return the lexicographically smallest equivalent string of baseStr
    for (int i = 0; i < n; i++)
    {
        char c1 = s1[i] - 'a';
        char c2 = s2[i] - 'a';
        findUnion(c1, c2);
    }
    // for each character in baseStr, find the smallest equivalent character
    string ans = "";
    for (int i = 0; i < baseStr.length(); i++)
    {
        char c = baseStr[i] - 'a';
        int parent_c = find(c);
        ans += char(parent_c + 'a');
    }
    return ans;
}

int main()
{
    string s1 = "parker";
    string s2 = "morris";
    string baseStr = "parser";
    cout << "\nlexicographically smallest equivalent string= " << smallestEquivalentString(s1, s2, baseStr);
    // makkek

    return 0;
}