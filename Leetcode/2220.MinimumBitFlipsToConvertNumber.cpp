#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal)
{
    int num=start^goal;
    return __builtin_popcount(num);
}

int main()
{
    int start = 10;
    int goal = 7;
    cout << "\nThe min no of bit flips reqd to convert " << start << " to " << goal << " = " << minBitFlips(start, goal);

    return 0;
}