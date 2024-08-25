#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n=nums.size();
    // for n, no of power sets=2^n ie 1<<n
    int noOfSubsets=(1<<n);
    // loop from 0 to noOfSubsets
    for(int i=0;i<noOfSubsets;i++){
        vector<int> set;
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                set.push_back(nums[j]);
            }
        }
        ans.push_back(set);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> powerSet = subsets(nums);
    for (auto it : powerSet)
    {
        cout << " [ ";
        for (auto elem : it)
        {
            cout << elem << " ";
        }
        cout << " ] ";
    }

    return 0;
}