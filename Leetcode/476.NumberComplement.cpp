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
    reverse(binary.begin(), binary.end());
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

int brute_force(int num)
{
    vector<int> bin = convertDecimalToBinary(num);
    for (int i = 0; i < bin.size(); i++)
    {
        if (bin[i] == 1)
        {
            bin[i] = 0;
        }
        else
        {
            bin[i] = 1;
        }
    }
    int ans = convertBinaryToDecimal(bin);
    return ans;
}

int findComplement(int num)
{
    if (num == 0)
    {
        return 1;
    }
    // count no of digits in num
    int countDigits = 0;
    unsigned int temp = num;        //to avoid runtime error use unsigned for + numbers
    while (temp > 0)
    {
        // right shift temp
        temp = temp >> 1;
        countDigits++;
        // eg: no of digits=3
    }
    // find mask as the largest number with all 111 with count=count of bits in n
    // ie 8: 1000
    unsigned int mask = 1 << countDigits;       //shift 1 for no of digit times
    // mask-1: 7-111
    mask = mask - 1;
    // 2. XOR
    return num ^ mask;
}

int main()
{
    // The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
    int num = 5;
    cout << "\nBRUTE FORCE-> The complement of n= " << num << " is= " << brute_force(num);
    cout << "\nThe complement of n= " << num << " is= " << findComplement(num);

    return 0;
}