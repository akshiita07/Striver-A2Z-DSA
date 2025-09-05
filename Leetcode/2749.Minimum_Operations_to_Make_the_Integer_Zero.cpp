#include <bits/stdc++.h>
using namespace std;

int makeTheIntegerZero(int num1, int num2)
{
    // return minimum number of operations needed to make num1 equal to 0 else return -1 if impossible
    // 1 operation: choose integer i in the range [0, 60] and num1 = num1 - (2^i + num2)
    // for k opertaions: 0=num1-k*num2 -(sum of k powers of 2)
    // so (sum of k powers of 2)= num1-k*num2
    for (int k = 1; k <= 60; k++)
    {
        long long rhs = 1LL * num1 - 1LL * k * num2;
        if (rhs < k)
        {
            continue;
        }
        if (__builtin_popcountll(rhs) <= k)
        {
            return k;
        }
    }
    return -1;
}

int main()
{
    int num1 = ;
    int num2 = ;

    return 0;
}