#include <bits/stdc++.h>
using namespace std;

//  UNset the rightmost set bit
int unSetBit(int n)
{
    return n&(n-1);
}

//  set the rightmost unset bit
int setBit(int n)
{
    return n|(n+1);
}

int main()
{
    int n = 12;
    // binary: 1100
    cout << "\nUnset the righmost bit from 1 to 0: " << unSetBit(n);
    cout << "\nSet the righmost bit from 0 to 1: " << setBit(n);

    return 0;
}