#include <bits/stdc++.h>
using namespace std;

int calSumAfterDivison(vector<int> &nums,int divisor){
    int result=0;
    // create copy of nums
    vector<int> temp=nums;
    int n=temp.size();
    for(int i=0;i<n;i++){
        temp[i]=(nums[i]+divisor-1)/divisor;      //i want ceil of division
        result+=temp[i];        //divided result sum
    }
    return result;
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    int low=1;
    int high=*max_element(nums.begin(),nums.end());
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        int result=calSumAfterDivison(nums,mid);

        if(result<=threshold){
            ans=mid;
            // check for smallest divisor
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

int main()
{

    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    cout<<"\nThe smallest divisor ie lesser than threshold "<<threshold<<" is: "<<smallestDivisor(nums,threshold);
    return 0;
}