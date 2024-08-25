#include <bits/stdc++.h>
using namespace std;

int findFirstRepeatingDigit(string digitPattern)
{
    int n = digitPattern.length();
    vector<int> hashMap(10, 0);     //for digits 0 to 9 including 9
    // traverse from front & check
    for (int i = 0; i < n; i++)
    {
        int digit=digitPattern[i]-'0';      //convert to int
        hashMap[digit]++;
        if (hashMap[digit] == 2)
        {
            return digit;
        }
    }
    return -1;
}

int main()
{
    // If no digit is repeating you should return -1.
    string digitPattern1 = "123456325";
    cout << "\nThe first repeating digit in " << digitPattern1 << " is= " << findFirstRepeatingDigit(digitPattern1);
    string digitPattern2 = "1234";
    cout << "\nThe first repeating digit in " << digitPattern2 << " is= " << findFirstRepeatingDigit(digitPattern2);

    return 0;
}