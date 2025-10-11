#include <bits/stdc++.h>
using namespace std;

long long maximumTotalDamage(vector<int> &power)
{
    // power[i]=damage of a spell[i]
    // if power[i] is cast then cannot cast power[i-2], power[i-1], power[i+1], power[i+2]
    unordered_map<int, long long> sum;
    for (auto it : power)
    {
        sum[it] += it;
    }

    vector<pair<int, long long>> arr(sum.begin(), sum.end());
    sort(arr.begin(), arr.end());

    int n = arr.size();
    vector<long long> dp(n);
    dp[0] = arr[0].second;

    for (int i = 1; i < n; i++)
    {
        // find previous index where power difference > 2
        int j = i - 1;
        while (j >= 0 && arr[i].first - arr[j].first <= 2)
        {
            j--;
        }
        long long take = arr[i].second + (j >= 0 ? dp[j] : 0);
        long long skip = dp[i - 1];
        dp[i] = max(take, skip);
    }
    return dp[n - 1];
}

int main()
{
    vector<int> power = {};

    return 0;
}