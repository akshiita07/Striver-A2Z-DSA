#include <bits/stdc++.h>
using namespace std;

int findLengthOfShortestSubarray(vector<int> &arr)
{
    // remove subarray from arr such that the remaining elements in arr are non-decreasing
    //  Return the length of the shortest subarray to remove
    int n = arr.size();
    // check if already sorted then return 0:
    if (is_sorted(arr.begin(), arr.end()))
    {
        return 0;
    }
    // find longest sorted left part
    int left = 0;
    while (left < n - 1 && arr[left] <= arr[left + 1])
    {
        left++;
        // left points at index 3
    }

    // find longest sorted right part
    int right = n - 1;
    while (right > 0 && arr[right] >= arr[right - 1])
    {
        right--;
        // right points at index 5
    }

    int lengthOfSubarr = min(n-left-1,right);
    // ie min of 8-3-1 and 5 ie min(4,5)=4

    // on merging left & right halfes:
    int i=0;        //i=0
    int j=right;    //j=5
    while(i<=left && j<n){
        if(arr[i]<=arr[j]){
            lengthOfSubarr = min(j-i-1,lengthOfSubarr);
            i++;
        }else{
            j++;
        }
    }
    return lengthOfSubarr;
}

int main()
{
    vector<int> arr = {1, 2, 3, 10, 4, 2, 3, 5};
    cout << "\nThe length of shorted subarray that must be removed from arr to get inc array is: " << findLengthOfShortestSubarray(arr);

    return 0;
}