#include <bits/stdc++.h>
using namespace std;

// DYNAMIC PROGRAMMING:
int hammingDistance(string &a, string &b)
{
    // we come to this function only if both a and b have same length:
    int n = a.length();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            cnt++;
        }
    }
    return cnt;
}

vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
{
    //  hamming distance between strings: corresponding positions where characetrs are DIFFERENT
    // words[i] & words[i+1] are euqal in length with hamming dist=1 and groups[i]!=groups[i+1]
    int n = words.size(); //==groups.size();
    vector<int> dp(n, 1);
    vector<int> prev(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (groups[i] != groups[j])
            {
                // if same length:
                if (words[i].length() == words[j].length())
                {
                    // check hamming distance:
                    if (hammingDistance(words[i], words[j]) == 1)
                    {
                        if (dp[j] + 1 > dp[i])
                        {
                            dp[i] = dp[j] + 1;
                            prev[i] = j;
                        }
                    }
                }
            }
        }
    }
    int maxLength = 0;
    int lastIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > maxLength)
        {
            maxLength = dp[i];
            lastIndex = i;
        }
    }
    vector<string> ans;
    while (lastIndex != -1)
    {
        ans.push_back(words[lastIndex]);
        lastIndex = prev[lastIndex];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<string> words = {"bab", "dab", "cab"};
    vector<int> groups = {1, 2, 2};
    vector<string> ans = getWordsInLongestSubsequence(words, groups);
    cout << "\nThe ans is: \n";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}