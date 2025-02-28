#include <bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string str1, string str2)
{
    // return the shortest string that has both str1 and str2 as subsequences
    // ie deleting some charac from our ans string must give us both str1 & str2
    int n1 = str1.size();
    int n2 = str2.size();
    // let dp[i][j] store longest common subsequence
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    // LCS= ab ie the part ie common in both
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                // if matching characters:
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                // if NOT matching :
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // backtract to construct final string:
    string ans = "";
    int i = n1;
    int j = n2;
    while (i > 0 && j > 0)
    {
        // i--;     j--;        keep on moving diagonally
        if (str1[i - 1] == str2[j - 1])
        {
            ans += str1[i - 1];
            i--;
            j--;
        }
        // If dp[i-1][j] > dp[i][j-1] take character from str1 else take from str2
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans += str1[i - 1];
            i--;
        }
        else
        {
            ans += str2[j - 1];
            j--;
        }
    }
    // add remaining chars:
    while (i > 0)
    {
        ans += str1[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans += str2[j - 1];
        j--;
    }
    // as we backtracked:
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string str1 = "abac";
    string str2 = "cab";
    cout << "\nShortest string that has both str1 and str2 as subsequences= " << shortestCommonSupersequence(str1, str2);

    return 0;
}