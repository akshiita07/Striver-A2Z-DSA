#include <bits/stdc++.h>
using namespace std;

bool brute_force(int n, int k)
{
    // first convert number to binary
    vector<int> bin;
    while (n != 0)
    {
        int rem = n % 2;
        bin.push_back(rem);
        n = n / 2;
    }
    // reverse(bin.begin(), bin.end());
    // now traverse backwards & check kth bit
    for (int i = 0; i < bin.size(); i++)
    {
        if (i == k)
        {
            if (bin[i] == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

// TIME: O(1)
// SPACE: O(1)
bool checkKthBit(int n, int k)
{
    // check left shift of 1 << k times
    // AND it with n
    //  if n>0->then set else unset
    if ((n & (1 << k)) > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// TIME: O(1)
// SPACE: O(1)
bool checkKthBitUsingRightShift(int n, int k)
{
    // check right shift of number >> k times
    // AND it with 1
    //  if n>0->then set else unset
    if (((n>>k)&(1)) > 0)
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
    int n = 13;
    int k1 = 1; // unset
    cout << "\nBRUTE FORCE: Check if " << k1 << " bit of " << n << " is set: " << brute_force(n, k1);
    cout << "\nUSING LEFT SHIFT: Check if " << k1 << " bit of " << n << " is set: " << checkKthBit(n, k1);
    cout << "\nUSING RIGHT SHIFT: Check if " << k1 << " bit of " << n << " is set: " << checkKthBitUsingRightShift(n, k1);
    int k2 = 2; // set
    cout << "\nBRUTE FORCE: Check if " << k2 << " bit of " << n << " is set: " << brute_force(n, k2);
    cout << "\nUSING LEFT SHIFT: Check if " << k2 << " bit of " << n << " is set: " << checkKthBit(n, k2);
    cout << "\nUSING RIGHT SHIFT: Check if " << k2 << " bit of " << n << " is set: " << checkKthBitUsingRightShift(n, k2);

    return 0;
}