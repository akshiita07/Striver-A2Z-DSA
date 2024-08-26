#include <bits/stdc++.h>
using namespace std;

string convertDecimalToBinary(int n)
{
    string binary = "";
    while (n != 0)
    {
        int remain = n % 2;
        binary += (remain + '0');
        n = n / 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

int convertBinaryToDecimal(string bin)
{
    int decimal = 0;
    int count = 0;
    // traverse backwards:
    for (int i = bin.length() - 1; i >= 0; i--)
    {
        if (bin[i] == '1')
        {
            decimal += 1 * pow(2, count);
        }
        count++;
    }
    return decimal;
}

string brute_force(string a, string b)
{
    int num1 = convertBinaryToDecimal(a);
    int num2 = convertBinaryToDecimal(b);
    int sum = num1 + num2;
    string ans = convertDecimalToBinary(sum);
    return ans;
}

string addBinary(string a, string b)
{
    if (a == "0" && b == "0")
    {
        return "0";
    }
    // start from end
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    string ans = "";
    while (i >= 0 || j >= 0 || carry > 0)
    {
        int sum = 0;
        sum += carry;
        if (i >= 0)
        {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0)
        {
            sum += b[j] - '0';
            j--;
        }
        carry = sum / 2; // if sum=2 then carry=1
        ans += ((sum % 2) + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string a = "11"; // decimal:3
    string b = "1";  // decimal:2
    // Output: "100"        //decimal:4
    cout << "\nBRUTE-> The sum of binary " << a << " and binary " << b << " gives= " << brute_force(a, b);
    cout << "\nThe sum of binary " << a << " and binary " << b << " gives= " << addBinary(a, b);

    return 0;
}