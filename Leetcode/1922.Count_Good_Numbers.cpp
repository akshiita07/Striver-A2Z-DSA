#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// to calculate base^exponent for large values
long long findPow(long long base, long long exponent)
{
    long long ans = 1;
    // continue loop until exponent becomes 0
    while (exponent > 0)
    {
        // if exponent is ODD:
        if (exponent % 2 != 0)
        {
            ans = (ans * base) % mod;
        }
        // halve the exponent and square the base
        base = (base * base) % mod;
        exponent = exponent / 2;
    }
    return ans;
}

int countGoodNumbers(long long n)
{
    // digits at EVEN (0,2,4,6,8,_ ) indexes must be EVEN (0,2,4,6,8) ie 5 options
    // digits at ODD (1,3,5,7,_ _) indexes must be PRIME (2,3,5,7) ie 4 options
    // return total no of good integers of length n modulo 10^9 + 7
    // no of even positions=ceil(n/2) ie (n+1)/2
    // no of odd positions=floor(n/2) ie n/2
    // total good intgers= 5^(even pos)*4^(odd pos)
    long long evenCount = (n + 1) / 2;
    long long oddCount = (n) / 2;
    long long evenWays = findPow(5, evenCount);
    long long oddWays = findPow(4, oddCount);
    return (evenWays * oddWays) % mod;
}

int main()
{
    long long n = 4;
    cout << "\n no of good integers=" << countGoodNumbers(n);

    return 0;
}