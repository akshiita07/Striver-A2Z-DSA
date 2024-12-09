#include <bits/stdc++.h>
using namespace std;

vector<bool> bruteForce(vector<int> &nums, vector<vector<int>> &queries)
{
    // special array: every pair of adjacent elements contains two numbers with different parity:ie odd even
    // queries[i] = [fromi, toi]
    // check that subarray nums[fromi..toi] is special or not
    vector<bool> ans;
    // iterate over each query now:
    for (int i = 0; i < queries.size(); i++)
    {
        int start = queries[i][0];
        int end = queries[i][1];
        bool isSpecial = true;
        // iterate over array now:
        for (int j = start; j < end; j++)
        {
            if (nums[j] % 2 == nums[j + 1] % 2)
            {
                // ie if same parity
                isSpecial = false;
                break;
            }
        }
        ans.push_back(isSpecial);
    }
    return ans;
}

vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
{
    // special array stores if adjacent elem have diff parity or not:
    vector<bool> special(n - 1, false);

    // Precompute if adjacent elements alternate in parity
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] % 2 != nums[i + 1] % 2)
        {
            special[i] = true;
        }
        // else by def false is intitialised in array
    }

    // Create a prefix sum array for the "special" array that will tell how many alternating elems exist
    vector<int> prefixSpecial(n, 0);
    for (int i = 0; i < nums.size() - 1; i++)
    {
        prefixSpecial[i + 1] = prefixSpecial[i] + (special[i] ? 1 : 0);
    }

    vector<bool> ans;
    // Process each query
    for (auto &it : queries)
    {
        int start = it[0];
        int end = it[1];
        // Check if all pairs in range [start, end] alternate in parity
        if (prefixSpecial[end] - prefixSpecial[start] == (end - start))
        {
            // if all alternate then true
            ans.push_back(true);
        }
        else
        {
            ans.push_back(false);
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 1, 6};
    vector<vector<int>> queries = {{0, 2}, {2, 3}};
    vector<bool> ans = isArraySpecial(nums, queries);
    cout << "Ans: \n";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}