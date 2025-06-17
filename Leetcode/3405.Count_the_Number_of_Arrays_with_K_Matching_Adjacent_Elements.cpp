#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxi = 1e5 + 5; // to handle n up to 1e5

long long fact[maxi], invFact[maxi];

// Modular exponentiation
long long modPow(long long a, long long b)
{
    long long res = 1;
    a %= mod;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void precomputeFactorials()
{
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < maxi; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    invFact[maxi - 1] = modPow(fact[maxi - 1], mod - 2);
    for (int i = maxi - 2; i >= 1; i--)
    {
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }
}

// nCk modulo mod
long long findNcK(int n, int k)
{
    if (k < 0 || k > n)
    {
        return 0;
    }
    return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}

int countGoodArrays(int n, int m, int k)
{
    // good array of size n
    // each element of arr must be 1<=elem<=m
    // k no of elements follow the condition: arr[i - 1] == arr[i]
    // Return the number of good arrays that can be formed.
    // first position has m choices & keep k elements with same value
    // remaining n-k-1 will have m-1 choices
    // formula: m * C(n-1,k)*(m-1)^(n-1-k)
    precomputeFactorials();
    long long c = findNcK(n - 1, k);
    long long diffChoices = modPow(m - 1, n - 1 - k);
    long long ans = m * (c % mod) * (diffChoices % mod);
    return ans % mod;
}

int main()
{
    int n = 3;
    int m = 2;
    int k = 1;
    cout << "\nnumber of good arrays that can be formed= " << countGoodArrays(n, m, k);

    return 0;
}