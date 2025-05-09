#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
// Time: O(N!∗N)
int brute_Force(string num)
{
    // balanced string: sum of digits at EVEN indices == sum of digits at ODD indices
    // Return the number of distinct permutations of num that are balanced.
    // 1. Find all distinct permutations of num
    string s = num;
    // sort it to get lexicographically ordered permutation
    sort(s.begin(), s.end());
    set<string> st;
    // 2. Check balanced condition for each permutation
    int count = 0;
    do
    {
        if (st.count(s) > 0)
        {
            // skip as already counted
            continue;
        }
        // add to set to avoid duplicates:
        st.insert(s);

        // check balanced:
        int evenSum = 0;
        int oddSum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            // convert char to int:
            int digit = s[i] - '0';
            if (i % 2 == 0 == 0)
            {
                // even index:
                evenSum += digit;
            }
            else
            {
                // odd index:
                oddSum += digit;
            }
        }
        if (evenSum == oddSum)
        {
            count = (count + 1) % mod;
        }

    } while (next_permutation(s.begin(), s.end())); // until all permutations are generated
    return count;
}

// Opitimal Approach:
constexpr static long long MOD = 1e9 + 7;

int countBalancedPermutations(string num)
{
    int tot = 0, n = num.size();
    vector<int> cnt(10);

    // Count digit frequencies and sum of all digits
    for (char ch : num)
    {
        int d = ch - '0';
        cnt[d]++;
        tot += d;
    }

    // If total sum is odd, it's impossible to split evenly
    if (tot % 2 != 0)
    {
        return 0;
    }

    // The target is half the sum of all digits
    int target = tot / 2;
    int maxOdd = (n + 1) / 2;

    // Precompute binomial coefficients for combinations
    vector<vector<long long>> comb(maxOdd + 1, vector<long long>(maxOdd + 1));
    for (int i = 0; i <= maxOdd; i++)
    {
        comb[i][i] = comb[i][0] = 1;
        for (int j = 1; j < i; j++)
        {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
        }
    }

    // DP table: f[curr][oddCnt] will store the number of ways to form `curr`
    // sum with `oddCnt` odd positions
    vector<vector<long long>> f(target + 1, vector<long long>(maxOdd + 1));
    f[0][0] = 1;

    int psum = 0, totSum = 0;

    // For each digit from 0 to 9, update the dp table
    for (int i = 0; i <= 9; i++)
    {
        psum += cnt[i];
        totSum += i * cnt[i];

        for (int oddCnt = min(psum, maxOdd); oddCnt >= max(0, psum - (n - maxOdd)); oddCnt--)
        {
            int evenCnt = psum - oddCnt;

            // Update the DP table based on current digit and its count
            for (int curr = min(totSum, target); curr >= max(0, totSum - target); curr--)
            {
                long long res = 0;

                // Try placing `j` occurrences of `i` in odd positions and
                // the remaining `cnt[i] - j` in even positions
                for (int j = max(0, cnt[i] - evenCnt); j <= min(cnt[i], oddCnt) && i * j <= curr; j++)
                {
                    long long ways = comb[oddCnt][j] * comb[evenCnt][cnt[i] - j] % MOD;
                    res = (res + ways * f[curr - i * j][oddCnt - j] % MOD) % MOD;
                }

                // Store the result in the DP table
                f[curr][oddCnt] = res % MOD;
            }
        }
    }

    // The answer is the number of ways to achieve the target sum with maxOdd odd positions
    return f[target][maxOdd];
}

int main()
{
    string num = "123";
    cout << "\nBrute_Force number of distinct permutations of num that are balanced= " << brute_Force(num);
    cout << "\nnumber of distinct permutations of num that are balanced= " << countBalancedPermutations(num);

    return 0;
}