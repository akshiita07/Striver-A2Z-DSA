#include <bits/stdc++.h>
using namespace std;

vector<int> brute_force(vector<string> &words, vector<vector<int>> &queries)
{
    // queries[i] = [li, ri]
    // find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
    vector<int> ans;
    int n = queries.size();
    for (int i = 0; i < n; i++)
    {
        int l = queries[i][0];
        int r = queries[i][1];
        int cnt = 0;
        for (int j = l; j <= r; j++)
        {
            string s = words[j];
            int len = s.length();
            // check 1st char:
            if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u')
            {
                // then check for last char
                if (s[len - 1] == 'a' || s[len - 1] == 'e' || s[len - 1] == 'i' || s[len - 1] == 'o' || s[len - 1] == 'u')
                {
                    // push it in ans:
                    cnt++;
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}

bool isVowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
        return true;
    }
    return false;
}
vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
{
    int n = words.size();
    vector<int> prefixSum(n + 1, 0);

    // Precompute the prefix sum of valid strings
    for (int i = 0; i < n; i++)
    {
        string s = words[i];
        if (isVowel(s[0]) && isVowel(s.back()))
        {
            prefixSum[i + 1] = prefixSum[i] + 1; // Increment if valid
        }
        else
        {
            prefixSum[i + 1] = prefixSum[i]; // Carry forward the previous count
        }
    }

    // Answer the queries
    vector<int> ans;
    for (auto &it : queries)
    {
        int l = it[0];
        int r = it[1];
        // Use the prefix sum to find the count in range [l, r]
        ans.push_back(prefixSum[r + 1] - prefixSum[l]); 
    }

    return ans;
}

int main()
{
    vector<string> words = {"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};
    // vector<int> ans = brute_force(words, queries);
    vector<int> ans = vowelStrings(words, queries);
    cout << "Ans:\n";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}