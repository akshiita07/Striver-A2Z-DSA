#include <bits/stdc++.h>
using namespace std;

/* brute force:
bool isSubsequence(string &s, string &t)
{
    // Check if t is a subsequence of s
    int i = 0;
    for (auto it : s)
    {
        if (it == t[i])
        {
            i++;
        }
        if (i == t.size())
        {
            return true;
        }
    }
    return false;
}

void backtrack(string &validChars, string &s, string &current, int k, string &best, int maxLen)
{
    if (current.size() > maxLen)
    {
        return;
    }

    if (!current.empty())
    {
        string multiplied = "";
        for (int i = 0; i < k; i++)
        {
            multiplied += current;
        }
        if (isSubsequence(s, multiplied))
        {
            if (current.size() > best.size() || (current.size() == best.size() && current > best))
            {
                best = current;
            }
        }
    }

    for (auto it : validChars)
    {
        current.push_back(it);
        backtrack(validChars, s, current, k, best, maxLen);
        current.pop_back();
    }
}

string longestSubsequenceRepeatedK(string s, int k)
{
    int n = s.length();
    //  find the longest subsequence repeated k times in string s
    // if multiple then return lexicographically largest one
    // first let us maintain count of each characteer as for k times repetition count of char must be>=k
    unordered_map<char, int> hashMap;
    for (int i = 0; i < n; i++)
    {
        hashMap[s[i]]++;
    }
    // discard characters with count less than k
    string validChars = "";
    for (auto it : hashMap)
    {
        if (it.second >= k)
        {
            validChars += it.first;
        }
    }
    string best = "";
    string current = "";
    int maxLen = n / k;
    backtrack(validChars, s, current, k, best, maxLen);
    return best;
}
*/

// optimal:
bool isKRepeatedSubsequence(string &s, string &seq, int k)
{
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < s.size())
    {
        if (s[i] == seq[j])
        {
            j++;
            if (j == seq.size())
            {
                j = 0;
                count++;
                if (count == k)
                {
                    return true;
                }
            }
        }
        i++;
    }
    return false;
}

string longestSubsequenceRepeatedK(string s, int k)
{
    int n = s.length();
    //  find the longest subsequence repeated k times in string s
    // if multiple then return lexicographically largest one
    // first let us maintain count of each characteer as for k times repetition count of char must be>=k
    unordered_map<char, int> hashMap;
    for (int i = 0; i < n; i++)
    {
        hashMap[s[i]]++;
    }
    // discard characters with count less than k
    string validChars = "";
    for (auto it : hashMap)
    {
        if (it.second >= k)
        {
            validChars += it.first;
        }
    }

    queue<string> q;
    string ans = "";
    for (auto it : validChars)
    {
        q.push(string(1, it));
    }

    int maxLen = n / k;

    while (!q.empty())
    {
        string cur = q.front();
        q.pop();

        if (cur.size() > maxLen)
        {
            continue;
        }

        if (isKRepeatedSubsequence(s, cur, k))
        {
            if (cur.size() > ans.size() || (cur.size() == ans.size() && cur > ans))
            {
                ans = cur;
            }
            for (auto it : validChars)
            {
                q.push(cur + it);
            }
        }
    }

    return ans;
}

int main()
{
    string s = "letsleetcode";
    int k = 2;
    cout << "\nLongest Subsequence Repeated K Times: " << longestSubsequenceRepeatedK(s, k);

    return 0;
}