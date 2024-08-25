#include <bits/stdc++.h>
using namespace std;

int toggleKthBit(int n, int k)
{
    int num = n;
    for (int i = 0; i < k; i++)
    {
        num = num ^ (1 << i);
    }
    return num;
}

int toggleBits(int n, int l, int r)
{
    // 1 based indexing
    int ans=n;
    for(int i=l-1;i<r;i++){
        ans=ans^(1<<i);
    }
    return ans;
}

int main()
{
    int n = 12;
    // binary:1100
    int k = 2;
    cout << "\nNumber after toggling " << k << " bit of " << n << " is= " << toggleKthBit(n, k);

    int num = 17;
    // bin: 10001
    int l = 2;
    int r = 3;
    cout << "\nNumber after toggling " << l<<" to "<<r << " bits of " << num << " is= " << toggleBits(num, l,r);

    return 0;
}