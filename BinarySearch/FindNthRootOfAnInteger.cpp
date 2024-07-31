#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: TIME-->O(m*n)
int brute_force(int n, int m)
{
    // return m(1/n)
    //   numb^n=m
    // if n not int then return -1
    for (int i = 1; i <= m; i++) // till m times
    {
        long long ans = 1;
        for (int j = 1; j <= n; j++)
        {
            ans *= i;
            if (ans > m)
            {
                break;
            }
        }
        if (ans == m)
        {
            return i;
        }
    }
    return -1;
}

// BINARY SEARCH: TIME-O(log2m)*O(logn)->for cal power
int findPow(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= mid;

        if (ans > m)
        {
            return 2;
        }
    }
    if (ans == m)
    {
        return 1;
    }
    if (ans < m)
    {
        return 3;
    }
}
int NthRoot(int n, int m)
{
    // Write your code here.
    int low = 1;
    int high = m;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        long long cal = findPow(mid, n, m); //to avoid any overflows

        if (cal == 1)
        {
            return mid;
        }
        else if (cal == 2)      //power>mid
        {
            high = mid - 1;
        }
        else if (cal == 3)     //power<mid
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n1 = 3;
    int m1 = 27;
    cout << "BRUTE FORCE--> The number: " << brute_force(n1, m1) << " when raised to power " << n1 << " gives number " << m1 << endl;
    cout << "The number: " << NthRoot(n1, m1) << " when raised to power " << n1 << " gives number " << m1 << endl;
    int n2 = 4;
    int m2 = 69;
    cout << "The number: " << NthRoot(n2, m2) << " when raised to power " << n2 << " gives number " << m2 << endl;
    return 0;
}