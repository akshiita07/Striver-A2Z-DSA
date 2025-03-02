#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
{
    // include ids in ascending order with value as sum of both arrays
    unordered_map<int, int> hashMap;
    // first lets traverse first array
    for (int i = 0; i < nums1.size(); i++)
    {
        int id = nums1[i][0];
        int value = nums1[i][1];
        hashMap[id] += value;
    }
    // now lets traverse second array & if a particular id is already present then add its value
    for (int i = 0; i < nums2.size(); i++)
    {
        int id = nums2[i][0];
        int value = nums2[i][1];
        if (hashMap.find(id) != hashMap.end())
        {
            hashMap[id] += value;
        }
        else
        {
            // otherwise create new id with value
            hashMap[id] += value;
        }
    }
    // convert hashMap to vector sorted by ids:
    vector<vector<int>> ans;
    for (auto it : hashMap)
    {
        ans.push_back({it.first, it.second});
    }
    sort(ans.begin(), ans.end(), [](const vector<int> &id1, const vector<int> &id2)
         { return id1[0] < id2[0]; });
    return ans;
}

int main()
{
    vector<vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> nums2 = {{1, 4}, {3, 2}, {4, 1}};
    // Output: [[1,6],[2,3],[3,2],[4,6]]
    vector<vector<int>> ans = mergeArrays(nums1, nums2);
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}