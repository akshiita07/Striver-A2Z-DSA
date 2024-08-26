#include <bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int n)
{
    // for overflow convert int n to long long
    long long nn = n;
    if (nn == 0)
    {
        return false;
    }
    if (((nn & (nn - 1)) == 0) && ((nn-1)%3==0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // check if a number is power of 2 or not
    int n1 = 16;
    cout << "\nIs " << n1 << "  a power of 4: " << isPowerOfFour(n1);
    int n2 = 5;
    cout << "\nIs " << n2 << "  a power of 4: " << isPowerOfFour(n2);

    return 0;
}