﻿#include <bits/stdc++.h>
using namespace std;

void rotate(int nums[], int k, int n)
{
    // rotation logic-
    
    // if k>n
    k = k % n;

    // reverse whole from 0 to n
    reverse(nums, nums + n);
    // first reverse from 0 to k
    reverse(nums, nums + k);
    // reverse from k+1 to n
    reverse(nums + k, nums + n);

    cout << "After rotating array by " << k << " steps to right: \n";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 3; // rotate array by 3 steps to right
    rotate(nums, k, n);

    return 0;
}