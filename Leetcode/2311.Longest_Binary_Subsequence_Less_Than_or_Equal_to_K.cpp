#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(string s, int k)
{
    // length of longest subsequence of s that makes up a binary number <= k
    // subsequence can contain leading zeros
    // for longest try removing earlier bits so value remains<=k
    int count = 0;
    long long value = 0;
    int power = 0;
    int n = s.size();

    // Traverse from right ie LSB
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            // Always safe to include 0
            count++;
        }
        else
        {
            // s[i] == '1'
            if (power < 31 && value + (1LL << power) <= k)
            {
                value += (1LL << power);
                count++;
            }
        }
        power++;
    }

    return count;
}

int main()
{
    string s = "1001010";
    int k = 5;
    cout << "\nLongest Binary Subsequence Less Than or Equal to K: " << longestSubsequence(s, k);

    return 0;
}