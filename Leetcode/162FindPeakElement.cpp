#include <bits/stdc++.h>
using namespace std;

// TIME: O(logn)
int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    // if only single element in array
    if(n==1){
        return 0;   //index return karna hai
    }
    // array range: -♾️[]-♾️
    // check for first element
    if(nums[0]>nums[1] && nums[0]>INT_MIN){
        return 0;   //index return karna hai
    }
    // check for last element
    if(nums[n-1]>nums[n-2] && nums[n-1]>INT_MIN){
        return n-1;   //index return karna hai
    }
    int low=1;
    int high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
            return mid;   //index return karna hai
        }else{
            if(nums[mid]<nums[mid+1]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return -1;  //if no peak element
}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << "\nThe peak element is: " << findPeakElement(nums);
    return 0;
}