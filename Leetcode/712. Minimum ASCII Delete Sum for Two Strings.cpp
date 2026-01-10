class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // lowest ASCII sum of deleted characters to make two strings equal
        int l1 = s1.length();
        int l2 = s2.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

        // DP to find max ASCII sum of common subsequence
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int totalSum = 0;
        for (char c : s1) {
            totalSum += c;
        }
        for (char c : s2) {
            totalSum += c;
        }

        return totalSum - 2 * dp[l1][l2];
    }
};
