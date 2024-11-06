#include <bits/stdc++.h>
using namespace std;

// int countNumberOfSetBits(int n){
//     // Built-in function for counting set bits
//     return __builtin_popcount(n);
// }

// bool canSortArray(vector<int> &nums)
// {
//     // swap any two adjacent elements if they have the same number of set bits

//     // check if already sorted then return true
//     if(is_sorted(nums.begin(),nums.end())){
//         return true;
//     }

//     // take map to map the no of set bits with elements of vector it has
//     unordered_map<int,vector<int>> bitGroup;

//     // group numbers:
//     for(int i=0;i<nums.size();i++){
//         int setBits=countNumberOfSetBits(nums[i]);
//         bitGroup[setBits].push_back(nums[i]);
//     }

//     // sort these vector groups:
//     // use & so that it actually sorts the actual vectors
//     for(auto& it:bitGroup){
//         sort(it.second.begin(),it.second.end());
//     }

//     vector<int> sortedArr;
//     for(int i=0;i<nums.size();i++){
//         int setBits=countNumberOfSetBits(nums[i]);
//         sortedArr.push_back(bitGroup[setBits].front());
//         bitGroup[setBits].erase(bitGroup[setBits].begin());
//     }

//     if(is_sorted(sortedArr.begin(),sortedArr.end())){
//         return true;
//     }
//     return false;
// }

bool canSortArray(vector<int> &nums)
{
    int maxValOfPrevGroup = 0;
    int i = 0;
    int n = nums.size();
    // iterate thru nums array:
    while (i < n)
    {
        int noOfSetBits = __builtin_popcount(nums[i]);
        int j = i + 1;
        int minEle = nums[i];
        int maxEle = nums[i];
        while (j < n && __builtin_popcount(nums[j]) == noOfSetBits)
        {
            minEle = min(minEle, nums[j]);
            maxEle = max(maxEle, nums[j]);
            j++;
        }
        if (maxValOfPrevGroup > minEle)
        {
            // If maxValOfPrevGroup is greater than minEle, then it’s impossible to sort nums
            return false;
        }
        maxValOfPrevGroup = maxEle;
        i = j;
    }
    return true;
}

int main()
{
    vector<int> nums = {8, 4, 2, 30, 15};
    cout << "\nCan array be sorted: " << canSortArray(nums);

    return 0;
}