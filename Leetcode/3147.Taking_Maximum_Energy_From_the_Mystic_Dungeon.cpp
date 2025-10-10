#include <bits/stdc++.h>
using namespace std;

int brute_force(vector<int> &energy, int k)
{
    // get energy from magician i then move to magician (i+k)-> teleport with k jumps
    // return maximum possible energy you can gain
    int ans = INT_MIN;
    int n = energy.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        // make j jump k times
        for (int j = i; j < n; j += k)
        {
            sum += energy[j];
        }
        ans = max(ans, sum);
    }
    return ans;
}

int maximumEnergy(vector<int> &energy, int k)
{
    // get energy from magician i then move to magician (i+k)-> teleport with k jumps
    // return maximum possible energy you can gain
    int ans = INT_MIN;
    int n = energy.size();
    vector<int> dp(n, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = energy[i];
        if (i + k < n)
        {
            // within range:
            dp[i] += dp[i + k];
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main()
{

    return 0;
}