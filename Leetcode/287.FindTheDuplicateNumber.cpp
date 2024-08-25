#include <bits/stdc++.h>
using namespace std;

int brute_force(vector<int> &nums)
{
    int n=nums.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            // xor of same numbers=0
            if(nums[i]==nums[j]){
                // ie same number found
                return nums[i];
            }
        }
    }
    return -1;
}

int better(vector<int> &nums)
{
    int n=nums.size();
    vector<int> hashMap(10,0);
    for(int i=0;i<n;i++){
        hashMap[nums[i]]++;
        if(hashMap[nums[i]]==2){
            return nums[i];
        }
    }
    return -1;
}

// TIME: O(n)
// SPACE: O(1)
int findDuplicate(vector<int> &nums)
{
    int n=nums.size();
    
    int slow=nums[nums[0]];
    int fast=nums[nums[nums[0]]];
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[nums[fast]];
    }
    slow=nums[0];
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[fast];
    }
    return slow;
}

int main()
{
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << "\nAPPROACH 1->The duplicate number is: " << brute_force(nums);
    cout << "\nAPPROACH 2->The duplicate number is: " << better(nums);
    cout << "\nAPPROACH 3->The duplicate number is: " << findDuplicate(nums);

    return 0;
}