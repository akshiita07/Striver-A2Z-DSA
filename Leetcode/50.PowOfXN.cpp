#include <bits/stdc++.h>
using namespace std;

double brute_force(double x, int n)
{
    double ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= x;
    }
    return ans;
}

double myPow(double x, int n)
{
    if (x == 0 || x == 1)
    {
        // if number is 0/1 then return that itself
        return x;
    }
    long long N = n;    //convert so that no overflow occurs
    if (n < 0)
    {
        N = N * (-1); // convert to +
    }
    double ans = 1;
    while (N > 0)
    {
        // if even->divide by 2
        if (N % 2 == 0)
        {
            N = N / 2;
            x = x * x; // square
        }
        // if odd-> make it even  by multply with ans
        else
        {
            ans = ans * x;
            N = N - 1;
        }
    }
    if (n < 0)
    {
        ans = double(1.0) / double(ans);
    }
    return ans;
}

int main()
{
    double x1 = 2.00;
    int n1 = 10;
    cout << x1 << " to the power of " << n1 << " is: " << brute_force(x1, n1) << endl;
    cout << x1 << " to the power of " << n1 << " is: " << myPow(x1, n1) << endl;

    double x2 = 2.00;
    int n2 = -2;
    cout << x2 << " to the power of " << n2 << " is: " << myPow(x2, n2) << endl;

    double x3 = 2.10;
    int n3 = 3;
    cout << x3 << " to the power of " << n3 << " is: " << myPow(x3, n3) << endl;

    return 0;
}