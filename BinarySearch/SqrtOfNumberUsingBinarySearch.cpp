#include <bits/stdc++.h>
using namespace std;
// YOU WILL ALWAYS BE GIVEN RANGE!!

// brute force..    TIME:O(n)
int brute_force(int n)
{
    int ans;
    for (int i = 1; i <= n; i++)
    {
        ans = i * i;
        if (ans == n)
        {
            return i;
        }
        else if (ans > n)
        {
            return (i - 1);
        }
    }
}


// binary search..    TIME:O(n^2)
int floorSqrt(int n)
{
    // find sqrt
    // if not a perfect square then return floor value of sqrt

    // base case:
    if(n==0 || n==1){
        return n;
    }

    int ans;
    int low=1;
    int high=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid*mid<=n){
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}

int main()
{
    int n1 = 100;
    cout << "\nBrute Force: Sqrt of " << n1 << " is: " << brute_force(n1);
    cout<<"\nSqrt of "<<n1<<" is: "<<floorSqrt(n1);
    int n2 = 7;
    cout << "\nBrute Force: Sqrt of " << n2 << " is: " << brute_force(n2);
    cout<<"\nSqrt of "<<n2<<" is: "<<floorSqrt(n2);

    return 0;
}