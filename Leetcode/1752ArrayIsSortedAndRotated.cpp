﻿#include <bits/stdc++.h>
using namespace std;

// isSorted
bool isSortedFnc(vector<int> arr)
{
    bool isSorted = true; // if only 1 element in arr then it is by default sorted!
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] <= arr[i + 1])
        {
            isSorted = true;
        }
        else
        {
            isSorted = false;
            break;
        }
    }
    return isSorted;
}

// BRUTE FORCE- O(n^2)
bool check(int nums[], int n)
{
    // array A rotated by x results in an array B of same length ➡️ A[i] == B[(i+x) % A.length]

    // choose a value of x
    for (int x = 0; x < n; x++)
    {
        vector<int> rotatedArray;
        for (int i = 0; i < n; i++)
        {
            rotatedArray.push_back(nums[(i + x) % n]);
        }

        cout << "\nThe rotated array by " << x << " is: \n";
        for (auto it : rotatedArray)
        {
            cout << it << " ";
        }
        cout << endl;

        // is sorted
        if (isSortedFnc(rotatedArray))
        {
            return true;
        }
    }
}

// OMTIMIZED- O(n)- IF NO OF ROATTAION POINTS>1 THEN ARRAY IS NOT SORTED
bool optimizedCheck(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[(i + 1) % n])
        { // to check if last index>first index or not
            count++;
        }
        if(count>1){
            return false;
            // more than 1 roattion point so cannot be sorted
        }
    }
    return true;
}

int main()
{
    // int nums[] = {3, 4, 5, 1, 2};
    int nums[] = {2, 1, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    // cout << "Is array sorted?: " << check(nums, n);      //brute force
    cout << "Is array sorted?: " << optimizedCheck(nums, n);         //optimized

    return 0;
}