// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> countDigits(int n)
{
    vector<int> ans(10, 0);
    while (n > 0)
    {
        int digit = n % 10;
        ans[digit]++;
        n = n / 10;
    }
    return ans;
}

bool reorderedPowerOf2(int n)
{
    // reorder digits of number n such that leading number is not 0
    // return true if number formed after reordering digits is a power of 2
    vector<int> count = countDigits(n);
    // try precomputing all powers of 2 & check if they have same digit count then return true
    // constraint given on n till 10^9
    // and 2^30=10^9
    for (int i = 0; i < 31; i++)
    {
        int powerOf2 = 1 << i;
        vector<int> digitsInPower = countDigits(powerOf2);
        if (count == digitsInPower)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n1 = 1;
    cout << "\nans1= " << reorderedPowerOf2(n1);
    int n2 = 10;
    cout << "\nans2= " << reorderedPowerOf2(n2);
    return 0;
}