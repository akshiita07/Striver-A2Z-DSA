#include <bits/stdc++.h>
using namespace std;

int countSetBits(int num)
{
    return __builtin_popcount(num); // returns no of set bits
}

int minimizeXor(int num1, int num2)
{
    int x = 0;
    //  x xor num1->minimal
    // x has same no of set bits as in num2
    int noOfSetBits = countSetBits(num2);

    // Greedily use bits from num1 to match the count of set bits in num2
    for (int i = 31; i >= 0 && noOfSetBits > 0; i--)
    {
        if (num1 & (1 << i))
        {                  // Check if the ith bit in num1 is set
            x |= (1 << i); // Set the ith bit in x
            --noOfSetBits; // Decrement the number of set bits required
        }
    }

    // If there are still set bits left to be added, add them from LSB upwards
    for (int i = 0; i <= 31 && noOfSetBits > 0; i++)
    {
        if (!(x & (1 << i)))
        {                  // Check if the ith bit in x is not set
            x |= (1 << i); // Set the ith bit in x
            --noOfSetBits; // Decrement the number of set bits required
        }
    }
    return x;
}

int main()
{
    int num1 = 3;
    int num2 = 5;
    cout << "\nValue of x: " << minimizeXor(num1, num2);

    return 0;
}