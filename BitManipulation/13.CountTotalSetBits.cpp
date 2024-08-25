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

int hammingWeight(int n)
{
    if (n == 0)
    {
        return 0;
    }
    // convert to binary
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        vector<int> binary = convertDecimalToBinary(i);
        // check no of set bits
        for (int j = 0; j < binary.size(); j++)
        {
            if (binary[j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}

int optimal(int n)
{
    if (n == 0)
    {
        return 0;
    }
    // convert to binary
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        count+=__builtin_popcount(i);
    }
    return count;
}

int main()
{
    // count the number of 1 bits from 1 to n:
    int n1 = 4;
    cout << "\nThe number of set bits from 1 to " << n1 << "  are: " << hammingWeight(n1);
    int n2 = 13;
    cout << "\nThe number of set bits from 1 to " << n1 << "  are: " << hammingWeight(n2);

    return 0;
}