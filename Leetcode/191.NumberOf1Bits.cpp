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
    return count;
}

int usingSTL(int n)
{
    if (n == 0)
    {
        return 0;
    }
    // check no of set bits
    int count = __builtin_popcount(n);
    return count;
}

int anotherApproach(int n)
{
    if (n == 0)
    {
        return 0;
    }
    // check no of set bits
    int count=0;
    while(n!=0){
        n=n&(n-1);
        count++;
    }
    return count;
}

int main()
{
    // count the number of 1 bits:
    int n1 = 16;
    cout << "\nThe number of set bits in " << n1 << "  are: " << hammingWeight(n1);
    cout << "\nUSING C++ STL-> The number of set bits in " << n1 << "  are: " << usingSTL(n1);
    cout << "\nUSING bitwise &-> The number of set bits in " << n1 << "  are: " << anotherApproach(n1);
    int n2 = 13;
    cout << "\nThe number of set bits in " << n2 << "  are: " << hammingWeight(n2);
    cout << "\nUSING C++ STL-> The number of set bits in " << n2 << "  are: " << usingSTL(n2);
    cout << "\nUSING bitwise &-> The number of set bits in " << n2 << "  are: " << anotherApproach(n2);

    return 0;
}