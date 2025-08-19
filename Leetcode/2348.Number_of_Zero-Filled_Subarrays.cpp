#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long zeroFilledSubarray(vector<int> &nums)
{
    // return the number of subarrays filled with 0
    int n = nums.size();
    // for each zero find the number of consecutive zeroes behind it
    vector<int> noOfConsecutiveZeroesBehind(n,0);
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            if(i>0){
                noOfConsecutiveZeroesBehind[i] =noOfConsecutiveZeroesBehind[i-1]+1;
            }else{
                noOfConsecutiveZeroesBehind[i] =0;
            }
        }
    }
    return accumulate(noOfConsecutiveZeroesBehind.begin(), noOfConsecutiveZeroesBehind.end(), 0LL);
}

int main()
{
    vector<int> nums = {0, 0, 0, 2, 0, 0};
    cout << "\nnumber of subarrays filled with 0= " << zeroFilledSubarray(nums);

    return 0;
}