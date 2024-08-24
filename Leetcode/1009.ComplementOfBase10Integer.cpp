#include <bits/stdc++.h>
using namespace std;

vector<int> convertDecimalToBinary(int n)
{
    vector<int> bin;
    while (n != 1)
    {
        int remain = n % 2;
        bin.push_back(remain);
        n = n / 2;
    }
    bin.push_back(1);
    reverse(bin.begin(), bin.end());
    return bin;
}

vector<int> findOnesComplement(vector<int> binary)
{
    for (int i = 0; i < binary.size(); i++)
    {
        if (binary[i] == 0)
        {
            binary[i] = 1;
        }
        else
        {
            binary[i] = 0;
        }
    }
    return binary;
}

int convertBinaryToDecimal(vector<int> binary)
{
    int decimal = 0;
    int count = 0;
    // backward traverse:
    for (int i = binary.size() - 1; i >= 0; i--)
    {
        if (binary[i] == 1)
        {
            decimal += pow(2, count);
        }
        count++;
    }
    return decimal;
}

int bitwiseComplement(int n)
{
    if(n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 0;
    }
    // decimal as input
    // convert decimal to binary
    vector<int> binary = convertDecimalToBinary(n);
    // find 1s complement
    vector<int> ones = findOnesComplement(binary);
    // convert binary to decimal
    int ans = convertBinaryToDecimal(ones);
    return ans;
}

int main()
{
    int n = 10;
    cout << "\nThe 1s complement of " << n << " in decimal is: " << bitwiseComplement(n);

    return 0;
}