#include <bits/stdc++.h>
using namespace std;

int findClosest(int x, int y, int z)
{
    // x= position of person 1
    // y= position of person 2
    // z= position of person 3 -> does NOT move
    // Determine which person reaches Person 3 first when both 1 & 2 move twds 3 at same speed
    int diffPer1 = abs(z - x);
    int diffPer2 = abs(z - y);
    if (diffPer1 == diffPer2)
    {
        // both reach at same time
        return 0;
    }
    else if (diffPer1 < diffPer2)
    {
        // person 1 reaches first
        return 1;
    }
    else
    {
        // person 2 reaches first
        return 2;
    }
    return 0;
}

int main()
{
    int x = ;
    int y = ;
    int z = ;
    cout << "\nAns= " << findClosest(x, y, z);

    return 0;
}