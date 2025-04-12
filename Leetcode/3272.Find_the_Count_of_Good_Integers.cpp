#include <bits/stdc++.h>
using namespace std;

bool isDivisible(const string &num, int k)
{
    int mod = 0;
    for (char c : num)
    {
        mod = (mod * 10 + (c - '0')) % k;
    }
    return mod == 0;
}

long long countPermutations(vector<int> &freq, int n)
{
    long long fact[11] = {1};
    for (int i = 1; i <= 10; ++i)
        fact[i] = fact[i - 1] * i;

    long long total = fact[n];
    for (int f : freq)
        total /= fact[f];

    // If there are no 0s, return directly
    if (freq[0] == 0)
        return total;

    // Subtract permutations that start with 0
    long long invalid = 0;
    if (freq[0] > 0)
    {
        vector<int> temp = freq;
        temp[0]--;
        int rem = n - 1;

        long long perms = fact[rem];
        for (int f : temp)
            perms /= fact[f];
        invalid += perms;
    }

    return total - invalid;
}

long long countGoodIntegers(int n, int k)
{
    // x is k-palindromic if x is a palindrome & x is divisble by k
    // good interger: if digits can be re-arranged to form a k-palindromic
    // integer Return the count of good integers containing n digits
    int half = n / 2;
    bool isOdd = (n % 2);
    long long result = 0;

    // Use set to avoid repeated digit patterns
    set<vector<int>> seen;

    function<void(string)> dfs = [&](string halfStr)
    {
        if ((int)halfStr.size() == half)
        {
            string rev = halfStr;
            reverse(rev.begin(), rev.end());

            if (isOdd)
            {
                for (char mid = '0'; mid <= '9'; ++mid)
                {
                    string pal = halfStr + mid + rev;
                    if (pal[0] == '0')
                        continue;

                    if (isDivisible(pal, k))
                    {
                        vector<int> freq(10, 0);
                        for (char c : pal)
                            freq[c - '0']++;

                        // Only count unique digit frequency combinations
                        if (!seen.count(freq))
                        {
                            seen.insert(freq);
                            result += countPermutations(freq, n);
                        }
                    }
                }
            }
            else
            {
                string pal = halfStr + rev;
                if (pal[0] == '0')
                    return;

                if (isDivisible(pal, k))
                {
                    vector<int> freq(10, 0);
                    for (char c : pal)
                        freq[c - '0']++;

                    if (!seen.count(freq))
                    {
                        seen.insert(freq);
                        result += countPermutations(freq, n);
                    }
                }
            }
            return;
        }

        for (char d = (halfStr.empty() ? '1' : '0'); d <= '9'; ++d)
        {
            halfStr.push_back(d);
            dfs(halfStr);
            halfStr.pop_back();
        }
    };

    dfs("");
    return result;
}

int main()
{
    int n = 3;
    int k = 5;
    cout << "\n no of good integers=" << countGoodIntegers(n, k);

    return 0;
}