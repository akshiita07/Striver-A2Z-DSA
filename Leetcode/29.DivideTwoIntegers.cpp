#include <bits/stdc++.h>
using namespace std;

int brute_force(int dividend, int divisor)
{
    int sum = 0;
    int count = 0;
    while ((sum + divisor) <= dividend)
    {
        count += 1;
        sum += divisor;
    }
    return count;
}

int divide(int dividend, int divisor)
{
    // remove bigger numbers:
    if (dividend == divisor)
    {
        return 1;
    }
    // check for sign
    bool sign = true;
    if ((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor >= 0))
    {
        sign = false; // ie sign is negative
    }
    // store posiitve values only:
    long n = abs(dividend);
    long d = abs(divisor);
    long ans = 0;
    while (n >= d)
    {
        int count = 0;
        // check if 2^count is still greater or not
        while (n >= (d << (count+1)))
        {
            count++;
        }
        ans += (1 << count);
        n = n - (d << count);
    }
    // check for overflow
    if (ans == (1<<31) && sign == true)
    {
        return INT_MAX;
    }
    if (ans == (1<<31) && sign == false)
    {
        return INT_MIN;
    }
    if (sign == false)
    {
        return ans * (-1);
    }
    else
    {
        return ans;
    }
}

int main()
{
    int dividend = 22;
    int divisor = 3;
    cout << "\nBRUTE FORCE-> The integer division returns= " << brute_force(dividend, divisor);
    cout << "\nThe integer division returns= " << divide(dividend, divisor);

    return 0;
}