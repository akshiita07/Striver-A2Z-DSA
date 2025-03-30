#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s)
{
    // each letter must appear in ATMOST once (ie 1 or 0 times) partition
    // on concatenating partitons in order we must get back original string s
    // Return a list of integers representing the size of these parts.
    unordered_map<char, int> hashMap;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        // store last index of each character
        hashMap[s[i]] = i;
    }
    vector<int> ans;
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        end = max(end, hashMap[s[i]]);
        if (i == end)
        {
            // partition found
            ans.push_back(end - start + 1);
            // now start from next index
            start = i + 1;
        }
    }
    return ans;
}

int main()
{
    string s = "ababcbacadefegdehijhklij";
    vector<int> ans = partitionLabels(s);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}