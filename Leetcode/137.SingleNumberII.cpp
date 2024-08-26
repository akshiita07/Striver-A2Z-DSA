#include <bits/stdc++.h>
using namespace std;

// TIME: O(n*1)+O(n*1)==O(2n) with unordered map with complexity O(1)
// SPACE: O(n)->map
int brute_force(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> hashMap(0); // stores number and its count
    for (int i = 0; i < n; i++)
    {
        hashMap[nums[i]]++;
    }
    for (auto it : hashMap)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
}

// write all nums in binary & check no of bis at each index..if multiple of 3 then good else remaining one is ans
// TIME: O(32*n)
// SPACE: O(1)
int better_1(vector<int> &nums)
{
    int ans;
    // traverse 32 bits
    for(int i=0;i<32;i++){
        int count=0;
        for(int j=0;j<nums.size();j++){
            // find no of set bits
            if(nums[j] & (1<<i)){
                count++;
            }
        }
        if(count%3==1){
            // ie not a multiple of 3!!
            ans=ans | (1<<i);
        }
    }
    return ans;
}

// sort the array then start from 1st index & always move 3 places until a[i]!=a[i-1]
// TIME: O(nlogn)->sort + O(n/3)->loop for +3 times
// SPACE: O()
int better_2(vector<int> &nums)
{
    int ans;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    // start from i=1
    // move i 3 times
    for(int i=1;i<n;i=i+3){
        if(nums[i]!=nums[i-1]){
            return nums[i-1];
        }
    }
    // if traversed whole array & still ans not found then
    ans=nums[n-1];
    return ans;
}

// using buckets approach:
int singleNumber(vector<int> &nums)
{
    int ones=0;
    int twos=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        ones=(nums[i]^ones) & ~twos;
        twos=(nums[i]^twos) & ~ones;
    }
    return ones;
}

int main()
{
    // every element appears 3 times except 1
    // return element that appears only once!!
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
    cout << "\nBRUTE FORCE: The no that appears exactly once is: " << brute_force(nums);
    cout << "\nBETTER 1: The no that appears exactly once is: " << better_1(nums);
    cout << "\nBETTER 2: The no that appears exactly once is: " << better_2(nums);
    cout << "\nThe no that appears exactly once is: " << singleNumber(nums);

    return 0;
}