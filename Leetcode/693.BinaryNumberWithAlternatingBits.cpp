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

bool hasAlternatingBits(int n)
{
    // convert no of binary
    vector<int> bin = convertDecimalToBinary(n);
    // check if adjacent bits r same or not
    for (int i = 0; i < bin.size() - 1; i++)
    {
        if (bin[i] == bin[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n1 = 5; // 101
    cout << "\nDoes " << n1 << " have alternating bits: " << hasAlternatingBits(n1);
    int n2 = 7; // 111
    cout << "\nDoes " << n2 << " have alternating bits: " << hasAlternatingBits(n2);

    return 0;
}