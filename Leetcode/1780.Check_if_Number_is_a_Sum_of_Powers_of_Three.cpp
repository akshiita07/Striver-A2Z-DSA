#include <bits/stdc++.h>
using namespace std;

bool checkPowersOfThree(int n)
{
    // return true if can represent n as the sum of distinct powers of three
    // a number can be written as sum of powers of 3 if when decimal)10 no is converted to ternary)# then 2 must not appear in it
    string ternary = "";
    while (n > 0)
    {
        ternary += to_string(n % 3);
        n = n / 3;
    }
    // loop thru ternary to check if 2 present:
    for (int i = 0; i < ternary.size(); i++)
    {
        if (ternary[i] == '2')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n1 = 91;
    cout << "\nIs sum of distinct powers of 3: " << checkPowersOfThree(n1);
    int n2 = 21;
    cout << "\nIs sum of distinct powers of 3: " << checkPowersOfThree(n2);
    return 0;
}