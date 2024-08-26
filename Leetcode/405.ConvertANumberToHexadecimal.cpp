#include <bits/stdc++.h>
using namespace std;

string toHex(int num)
{
    if (num == 0)
    {
        return "0";
    }
    // base=16
    string hexadecimal = "";
    // to handle negatives:
    unsigned int n = num;
    while (n != 0)
    {
        int remain = (n % 16);
        if (remain <= 9)
        {
            hexadecimal += remain + '0';
        }
        else
        {
            // if greater:
            hexadecimal += remain - 10 + 'a';
        }
        n = n / 16;
    }
    reverse(hexadecimal.begin(), hexadecimal.end());
    return hexadecimal;
}

int main()
{
    int n1 = 26;
    cout << "\nThe number " << n1 << " in hexadecimal is: " << toHex(n1);
    // Output: "1a"

    int n2 = -1;
    cout << "\nThe number " << n2 << " in hexadecimal is: " << toHex(n2);
    // Output: "ffffffff"

    return 0;
}