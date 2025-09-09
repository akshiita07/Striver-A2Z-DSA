#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int peopleAwareOfSecret(int n, int delay, int forget)
{
    // after "dealy" no of days-> passes secret to others
    // forget the secret "forget" days after learning it
    // return the number of people who know the secret at the end of day n
    // let dp[j]-> ppl who know secret for j+1 days
    // person discovers secret on day1:
    dp[0] = 1;
    for (int day = 1; day < n; day++)
    {
        long long new_ppl = 0;
        // no of ppl who can share secret:
        for (int i = delay - 1; i < forget - 1; i++)
        {
            new_ppl = (new_ppl + dp[i]) % mod;
        }
        // shift days:
        for (int i = forget - 1; i > 0; i--)
        {
            dp[i] = dp[i - 1];
        }
        // update new ppl who know the secret
        dp[0] = new_ppl;
    }
    int ans = 0;
    for (int i = 0; i < forget; i++)
    {
        ans = (ans + dp[i]) % mod;
    }
    return ans;
}

int main()
{
    int n = 6;
    int delay = 2;
    int forget = 4;
    cout << "\nnumber of people who know the secret at the end of day " << n << " are: " << peopleAwareOfSecret(n, delay, forget);

    return 0;
}