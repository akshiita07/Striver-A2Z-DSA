#include <bits/stdc++.h>
using namespace std;

vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
{
    int n = words.size(); //==groups.size();
    // choose indices such that groups[i] != groups[i+1]
    vector<string> ans;
    ans.push_back(words[0]);
    for (int i = 1; i < n; i++)
    {
        if (groups[i] != groups[i - 1])
        {
            ans.push_back(words[i]);
        }
    }
    return ans;
}

int main()
{
    vector<string> words = {"e", "a", "b"};
    vector<int> groups = {0, 0, 1};
    vector<string> ans = getLongestSubsequence(words, groups);
    cout << "\nThe longest alternating subsequence is: \n";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}