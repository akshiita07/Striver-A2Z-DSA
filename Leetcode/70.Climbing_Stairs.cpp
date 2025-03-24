#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    // climb either 1 or 2 steps each time

    // base case: if standing at 0th stair then only 1 way:
    if (n == 0)
    {
        return 1;
    }

    // base case: if standing at 1th stair then only 1 way:
    if (n == 1)
    {
        return 1;
    }
    // jump 1: go 1 index
    int left = climbStairs(n - 1);
    // jump 2: go 2nd index
    int right = climbStairs(n - 2);
    return left + right;
}

// TABULATION: WITH SPACE OPTIMIZATION
int climbStairs(int n)
{
    // no of ways to making n using 1s & 2s
    if (n <= 1)
    {
        // base case:
        return 1; // only 1 possible way
    }
    int count1 = 1;
    int count2 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = count1 + count2;
        count1 = count2;
        count2 = curr;
    }
    return count2;
}

int main()
{
    int n = 3;
    cout << "\ndistinct ways can you climb to the top= " << climbStairs(n);

    return 0;
}