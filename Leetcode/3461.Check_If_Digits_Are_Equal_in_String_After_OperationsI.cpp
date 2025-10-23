#include <bits/stdc++.h>
using namespace std;

bool hasSameDigits(string s)
{
    // perform operations on string unitl it has exactly 2 digits
    // calculate a new digit =sum of the two digits % 10
    // Return true if the final two digits in s are the same
    int n = s.length();
    while (n > 2)
    {
        string ans = "";
        for (int i = 0; i < n - 1; i++)
        {
            int nextDigit = s[i] - '0';
            int nextNextDigit = s[i + 1] - '0';
            int sum = (nextDigit + nextNextDigit) % 10;
            char digit = sum + '0';
            ans += digit;
        }
        // update length & string:
        s = ans;
        n = s.length();
    }
    if (s[0] == s[1])
    {
        return true;
    }
    return false;
}

int main()
{

    return 0;
}