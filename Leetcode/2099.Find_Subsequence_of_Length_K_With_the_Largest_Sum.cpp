#include <bits/stdc++.h>
using namespace std;

vector<int> maxSubsequence(vector<int> &nums, int k)
{
    // find a subsequence of nums of length k that has the largest sum
    // sort array in descending order while maintaining index
    vector<pair<int, int>> withIndices;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        withIndices.push_back({nums[i], i});
    }
    sort(withIndices.begin(), withIndices.end(), greater<>());
    vector<int> indices;
    for (int i = 0; i < k; i++)
    {
        // first k elements of withIndices are chosen
        indices.push_back(withIndices[i].second);
    }
    sort(indices.begin(), indices.end());
    vector<int> ans;
    for (int i = 0; i < indices.size(); i++)
    {
        ans.push_back(nums[indices[i]]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {-1, -2, 3, 4};
    int k = 3;
    cout << "\nLargest sum= \n";
    vector<int> ans = maxSubsequence(nums, k);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}