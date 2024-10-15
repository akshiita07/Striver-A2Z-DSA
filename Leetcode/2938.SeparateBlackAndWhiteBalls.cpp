#include <bits/stdc++.h>
using namespace std;

long long minimumSteps(string s)
{
    int n = s.length();
    // 1:black
    // 0:white
    //  choose two adjacent balls and swap them
    // Return the minimum number of steps to group all the black balls to the right and all the white balls to the left
    // ie ___white_______ black_______ or ___0000___111____

    // if 10 present ie first black then white so swap them
    long long noOfSwaps = 0;
    int noOfBlackBalls = 0;

    // count all white balls while traversing thru all black balls
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            // it is black ball
            noOfBlackBalls++;
            noOfSwaps += (n - i - noOfBlackBalls);
        }
    }
    return noOfSwaps;
}

int main()
{
    string s = "100";
    cout << "\nNo of swaps reqd are: " << minimumSteps(s);

    return 0;
}