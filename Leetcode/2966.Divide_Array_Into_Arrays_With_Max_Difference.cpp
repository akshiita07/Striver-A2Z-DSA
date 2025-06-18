#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> divideArray(vector<int> &nums, int k)
{
    // n is a multiple of 3 & k
    int n = nums.size();
    // Divide array nums into n/3 arrays of size 3 st diff bw any 2 elements in one array <= k else return empty array
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    bool isValid = true;
    for (int i = 0; i < n; i += 3)
    {
        int a = nums[i];
        int b = nums[i + 1];
        int c = nums[i + 2];
        if (c - a > k)
        {
            return {};
        }
        ans.push_back({a, b, c});
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    int k = 2;
    vector<vector<int>> ans = divideArray(nums, k);
    cout << "\nAns:\n";
    for (auto row : ans)
    {
        for (auto it : row)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}