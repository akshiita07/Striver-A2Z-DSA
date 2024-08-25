#include <bits/stdc++.h>
using namespace std;

// TIME: O(n)
// SPACE: O(n)->for array
int xorOperation(int n, int start)
{
    // Define an array nums where nums[i] = start + 2 * i (0-indexed) and n == nums.length
    vector<int> arr;
    for(int i=0;i<n;i++){
        arr.push_back(start+(2*i));
    }
    // array is ready
    for(auto it:arr){
        cout<<it<<" ";
    }

    // now find xor of all elements of array
    int ans=0;
    for(auto it:arr){
        ans^=it;
    }
    return ans;
}

int main()
{
    int n = 5;
    int start = 0;
    cout << "\nBitwise XOR of elements = " << xorOperation(n, start);

    return 0;
}