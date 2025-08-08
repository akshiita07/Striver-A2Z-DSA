// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

unordered_map<int,unordered_map<int,double>> memoization;

double dfs(int A,int B){
    if(A<=0 && B<=0){
        return 0.5;
    }
    if(A<=0){
        return 1.0;
    }
    if(B<=0){
        return 0.0;
    }
    if(memoization[A][B]){
        return memoization[A][B];
    }

    //4 operations:
    double ans=0.25*(dfs(A-4,B) + dfs(A-3,B-1) + dfs(A-2,B-2) + dfs(A-1,B-3));
    return memoization[A][B]=ans;
}

double soupServings(int n)
{
    // 2 soups: A,B with n ml
    // 4 serving operations with probability: 0.25
    // (A,B)= 1(100,0), 2(75,25), 3(50,50), 4(25,75)
    // Return the probability that A is used up before B, plus half the probability that both soups are used up in the same turn

    //for a large value of n probability approaches 1
    if(n>5000){
        return 1.0;
    }
    //serving sizes are multiples of 25 so we scale down:
    int units=ceil(n/25.0);
    // updated (A,B)= 1(3,0), 2(3,1), 3(2,2), 4(1,3)
    // 3 cases:
    // both A & B empty at same time: 0.5 probability 
    // if A empty first then 1 probability
    // if B empty first then 0 probability

    return dfs(units,units);
}

int main()
{
    int n=50;
    cout<<"\nans= "<<soupServings(n);

    return 0;
}