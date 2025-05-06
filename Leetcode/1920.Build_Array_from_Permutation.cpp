#include <bits/stdc++.h>
using namespace std;

vector<int> brute_force(vector<int> &nums)
{
    // time:O(n)
    // space:O(n) extra space for ans array
    int n = nums.size();
    vector<int> ans(n);
    // ans[i] = nums[nums[i]]
    for (int i = 0; i < n; i++)
    {
        ans[i] = nums[nums[i]];
    }
    return ans;
}

vector<int> buildArray(vector<int> &nums)
{
    // time:O(n)
    // space:O(1)
    int n = nums.size();
    // encode both new & old vaues in a single array:
    for (int i = 0; i < n; i++)
    {
        nums[i] = nums[i] + n * (nums[nums[i]] % n);
    }
    // extract new values:
    for (int i = 0; i < n; i++)
    {
        nums[i] = nums[i] / n;
    }
    return nums;
}

int main()
{
    // Output: [0,1,2,4,5,3]
    vector<int> nums = {0, 2, 1, 5, 3, 4};
    vector<int> ans = brute_force(nums);
    cout << "\nBuilding array using brute force: \n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    vector<int> ans2 = buildArray(nums);
    cout << "\nBuilding array OPTIMALLY: \n";
    for (auto it : ans2)
    {
        cout << it << " ";
    }

    return 0;
}