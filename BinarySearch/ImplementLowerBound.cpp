#include <bits/stdc++.h>
using namespace std;
// time:O(logn)-> sorted array-> binary search
int lowerBound(vector<int> arr, int x)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans=mid;
            // move to left
            high=mid-1;
        }else if(arr[mid]<x){
            // move to right
            low=mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int x=9;
    cout << "The index of lower bound is: " << lowerBound(arr, x);

    return 0;
}