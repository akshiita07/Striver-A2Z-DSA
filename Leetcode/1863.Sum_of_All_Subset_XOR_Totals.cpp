#include <bits/stdc++.h>
using namespace std;

int ans = 0;
void dfs(vector<int> &nums, int index, int XORval)
{
    int n = nums.size();
    // at last subset:
    if (index == n)
    {
        ans += XORval;
        return;
    }
    // try including next element in this subset:
    dfs(nums, index + 1, XORval ^ nums[index]);
    // try excluding it:
    dfs(nums, index + 1, XORval);
}
int subsetXORSum(vector<int> &nums)
{
    // form all subsets of nums {},{a,b},{a,c},{b,c},{a,b,c},_ _
    // find xor of each subset
    // add all xor values
    dfs(nums, 0, 0); // start by excluding everything
    return ans;
}

int main()
{
    vector<int> nums = {5, 1, 6};
    cout << "\nSum of all subset XOR totals: " << subsetXORSum(nums);

    return 0;
}