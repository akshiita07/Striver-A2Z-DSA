#include <bits/stdc++.h>
using namespace std;

vector<int> convertDecimalToBinary(int n)
{
    vector<int> binary;
    while (n != 0)
    {
        int remain = n % 2;
        binary.push_back(remain);
        n = n / 2;
    }
    // reverse(binary.begin(),binary.end());
    return binary;
}

int convertBinaryToDecimal(vector<int> bin)
{
    int decimal = 0;
    int count = 0;
    // traverse backwards:
    for (int i = bin.size() - 1; i >= 0; i--)
    {
        decimal += bin[i] * pow(2, count);
        count++;
    }
    return decimal;
}

int brute_force(int n, int k)
{
    // convert given number n to binary
    vector<int> bin = convertDecimalToBinary(n);
    // traverse to kth bit
    for (int i = 0; i < bin.size(); i++)
    {
        // set the bit
        if (i == k)
        {
            bin[i] = 1;
        }
    }
    reverse(bin.begin(), bin.end());
    // convert no back to decimal
    int num = convertBinaryToDecimal(bin);
    return num;
}

int setKthBit(int n, int k)
{
    // using left shift operator:
    int num = (n | (1 << k));
    return num;
}

int main()
{
    int n = 9;
    // binary:1001
    int k1 = 1;
    cout << "\nBRUTE FORCE->Number after setting " << k1 << " bit to 1 of " << n << " is= " << brute_force(n, k1);
    cout << "\nNumber after setting " << k1 << " bit to 1 of " << n << " is= " << setKthBit(n, k1);
    int k2 = 3;
    cout << "\nBRUTE FORCE->Number after setting " << k2 << " bit to 1 of " << n << " is= " << brute_force(n, k2);
    cout << "\nNumber after setting " << k2 << " bit to 1 of " << n << " is= " << setKthBit(n, k2);

    return 0;
}