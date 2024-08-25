#include <bits/stdc++.h>
using namespace std;

pair<int, int> swapUsingTemp(int a, int b)
{
    int temp=a;
    a=b;
    b=temp;
    return {a,b};
}

pair<int, int> swapWithoutTemp(int a, int b)
{
    a=a^b;
    b=a^b;
    a=a^b;
    return {a,b};
}

int main()
{
    int a = 5;
    int b = 10;
    cout << "\nInitially a=" << a << " and b=" << b;
    // pair<int, int> ans = swapUsingTemp(a, b);
    pair<int, int> ans= swapWithoutTemp(a,b);
    cout << "\nAfter swap a=" << ans.first << " and b=" << ans.second;

    return 0;
}