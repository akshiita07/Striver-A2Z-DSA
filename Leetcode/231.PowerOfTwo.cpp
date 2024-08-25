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

bool brute_force(int n)
{
    // convert to binary
    vector<int> binary = convertDecimalToBinary(n);
    // check no of set bits
    int count = 0;
    for (int i = 0; i < binary.size(); i++)
    {
        if (binary[i] == 1)
        {
            count++;
        }
    }
    // if only 1 set bit=> yes
    if (count == 1)
    {
        return true;
    }
    // else->no
    else
    {
        return false;
    }
}

bool isPowerOfTwo(int n)
{
    // for overflow convert int n to long long
    // long long nn=n;
    if (n == 0)
    {
        return false;
    }
    if ((n & (n - 1)) == 0)
    {
        // will unset 1 set bit of power of 2
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // check if a number is power of 2 or not
    int n1 = 16;
    cout << "\nBRUTE FORCE-->Is " << n1 << "  a power of 2: " << brute_force(n1);
    cout << "\nIs " << n1 << "  a power of 2: " << isPowerOfTwo(n1);
    int n2 = 13;
    cout << "\nBRUTE FORCE-->Is " << n2 << "  a power of 2: " << brute_force(n2);
    cout << "\nIs " << n2 << "  a power of 2: " << isPowerOfTwo(n2);

    return 0;
}