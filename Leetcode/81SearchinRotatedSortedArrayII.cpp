#include <bits/stdc++.h>
using namespace std;

// return true if target is in nums, or false if it is not in nums
bool search(vector<int> &nums, int target)
{
    int n=nums.size();
    int low=0;
    int high=n-1;

    while(low<=high){
        int mid=(low+high)/2;

        // due to duplicates-->trim down 
        if(nums[mid]==nums[low]==nums[high]){
            // shink search space
            // eg:{3,1,2,3,3,3}
            low++;
            high--;
            continue;
        }
        if(nums[mid]==target){
            return true;
        }
        if(nums[low]<=nums[mid]){
            // left half: low to mid
            if(nums[low]<=target && target<=nums[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        else{
            // right half: mid to high
            if(nums[mid]<=target && target<=nums[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }

    return false;
}

int main()
{
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target1 =0 ;    //T
    int target2 =3 ;    //F
    cout<<"Does "<<target1<<" exists in array: "<<search(nums,target1)<<endl;
    cout<<"Does "<<target2<<" exists in array: "<<search(nums,target2)<<endl;
    return 0;
}