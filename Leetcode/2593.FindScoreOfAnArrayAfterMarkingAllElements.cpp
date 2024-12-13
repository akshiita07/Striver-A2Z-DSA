#include <bits/stdc++.h>
using namespace std;

long long findScore(vector<int> &nums)
{
    long long score = 0; // start
    // we create a sorted vector of pairs with <value,its index>
    vector<pair<int, int>> sortedNums;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        sortedNums.push_back({nums[i], i});
    }
    sort(sortedNums.begin(), sortedNums.end());

    // maintain a set to mark all set elements: add index in it
    set<int> marked;

    for (const auto& [value, index] : sortedNums)
    {
        // if elem not in marked set:
        if (marked.find(index) == marked.end())
        {
            // not found so add
            marked.insert(index);
            // add it
            score += value;
            // mark its adjacent elems:     check before if they exist?
            if (index + 1 < n)
            {
                marked.insert(index + 1);
            }
            if (index - 1 >= 0)
            {
                marked.insert(index - 1);
            }
        }
    }
    return score;
}

int main()
{
    vector<int> nums = {2, 3, 5, 1, 3, 2};
    cout << "\nScore is: " << findScore(nums);
    return 0;
}