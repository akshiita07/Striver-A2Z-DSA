#include <bits/stdc++.h>
using namespace std;

int smallestNumber(int n)
{
    // smallest no x>=n st binary representation of x contains all 1s (set bits)
    // next strictly greater power of 2-1
    // n>=1 so 2^1=2
    // 2^10=1024 and n<=1000 so loop till 10
    for (int i = 1; i <= 10; i++)
    {
        int powerOfTwo = pow(2, i);
        if (powerOfTwo > n)
        {
            return powerOfTwo - 1;
        }
    }
    return 0;
}

int main()
{

    return 0;
}