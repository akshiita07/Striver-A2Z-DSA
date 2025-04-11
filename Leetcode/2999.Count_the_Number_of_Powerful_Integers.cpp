#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string targetSuffix;
    int limitDigit;
    string t;
    long long dp[20];

    // count numbers ending with `targetSuffix`, digits ≤ limitDigit,and ≤
    // number `t`
    long long dfs(int pos, bool tight) {
        if (t.size() < targetSuffix.size())
            return 0;

        if (t.size() - pos == targetSuffix.size()) {
            string suffixCandidate = t.substr(pos);
            return (tight ? suffixCandidate >= targetSuffix : 1);
        }

        if (!tight && dp[pos] != -1)
            return dp[pos];

        long long ans = 0;
        int maxDigit = tight ? t[pos] - '0' : 9;
        maxDigit = min(maxDigit, limitDigit);

        for (int d = 0; d <= maxDigit; d++) {
            bool newTight = tight && (d == t[pos] - '0');
            ans += dfs(pos + 1, newTight);
        }

        if (!tight) {
            dp[pos] = ans;
        }
        return ans;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
        targetSuffix = s;
        limitDigit = limit;

        // Count powerful numbers ≤ finish
        t = to_string(finish);
        memset(dp, -1, sizeof(dp));
        long long countFinish = dfs(0, true);

        // Count powerful numbers ≤ start - 1
        t = to_string(start - 1);
        memset(dp, -1, sizeof(dp));
        long long countStartMinusOne = dfs(0, true);

        return countFinish - countStartMinusOne;
    }
};

int main()
{
    long long start = 1;
    long long finish = 6000;
    int limit = 4;
    string s = "124";
    cout << "\nNumber of powerful integers: " << numberOfPowerfulInt(start, finish, limit, s);

    return 0;
}
