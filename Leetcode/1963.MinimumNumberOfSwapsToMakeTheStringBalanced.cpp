#include <bits/stdc++.h>
using namespace std;

int minSwaps(string s)
{
    int balance = 0;
    int unmatched = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[')
        {
            // opening bracket so increment balance
            balance++;
        }
        else if (s[i] == ']')
        {
            // closing bracket so decrement balance
            balance--;
        }
        // if balance goes below 0:
        if (balance < 0)
        {
            // increment unmatches
            unmatched++;
            // reset balance back to 0
            balance = 0;
        }
    }
    // min no of swaps:
    return (unmatched + 1) / 2;
}

int main()
{
    string s = "][][";
    cout << "\nMin no of swaps reqd to make string balanced are: " << minSwaps(s);

    return 0;
}