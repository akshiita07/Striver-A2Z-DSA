#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
int numWays(vector<string> &words, string target)
{
    // words: list of strings of SAME LENGTH
    // To form the ith character of target: choose kth character of jth string from words if
    // target[i] = words[j][k]
    //  all characters to the left of or at index k become unusuable for every string
    int m = words[0].size(); // length of all strings
    int n = target.size();   // desired length

    // Frequency table: freq[c][j] gives the frequency of character c at column j
    vector<vector<int>> freq(26, vector<int>(m, 0));
    for (const string &it : words)
    {
        for (int j = 0; j < m; j++)
        {
            freq[it[j] - 'a'][j] += 1;
        }
    }

    // DP table: dp[i][j] is the number of ways to form target[0..i-1] using first j columns
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    dp[0][0] = 1; // Base case: 1 way to form an empty string

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Carry forward the previous value (skip column j)
            dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;

            if (i < n)
            {
                // Use column j to form target[i] if possible
                int charIdx = target[i] - 'a';
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * freq[charIdx][j]) % mod;
            }
        }
    }

    return dp[n][m];
}

int main()
{
    vector<string> words = {"acca", "bbbb", "caca"};
    string target = "aba";
    cout << "\nAns: " << numWays(words, target);

    return 0;
}