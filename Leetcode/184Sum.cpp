#include <bits/stdc++.h>
using namespace std;
// nums[a] + nums[b] + nums[c] + nums[d] == target & a,b,c,d are unique

// BRUTE FORCE: TIME-O(n^4)     SPACE:O(n)->temp array
void fourSum_brute(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            for (int k = j + 1; k < n - 1; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        // check for duplicate
                        if (find(ans.begin(), ans.end(), temp) == ans.end())
                        {
                            // ie not found then add
                            ans.push_back(temp);
                        }
                    }
                }
            }
        }
    }

    cout << "The 4 different numbers such that when added=" << target << " are: \n";
    for (auto row : ans)
    {
        for (auto it : row)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}

// BETTER:hash set TIME-O(n^3*1)-for unordered map     SPACE:O(n)->for set
void fourSum_better(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            unordered_set<int> hash;
            for (int k = j + 1; k < n; k++)
            {
                int forth = target - (nums[i] + nums[j] + nums[k]);
                // check if forth exists in hash
                if (hash.find(forth) != hash.end())
                {
                    // found
                    vector<int> temp = {nums[i], nums[j], nums[k], forth};
                    sort(temp.begin(), temp.end());
                    // check for duplicate
                    if (find(ans.begin(), ans.end(), temp) == ans.end())
                    {
                        // ie not found then add
                        ans.push_back(temp);
                    }
                }
                else
                {
                    // not present then add it
                    hash.insert(nums[k]);
                }
            }
        }
    }

    cout << "The 4 different numbers such that when added=" << target << " are: \n";
    for (auto row : ans)
    {
        for (auto it : row)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}

// OPTIMAL:  TIME-O(n^2)+O(n)-for k,l while loop==O(n^3)time     SPACE:O(1)->no extra space
void fourSum_optimal(vector<int> &nums, int target)
{
    // initially sort array
    sort(nums.begin(), nums.end());
    // -2   -1   0   0   1   2
    int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n - 1; i++)
    {
        // until same j ->loop
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            // until same j ->loop
            if (j != i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                int sum = nums[i] + nums[j] + nums[k] + nums[l];
                if (sum > target)
                {
                    l--;
                }
                else if (sum < target)
                {
                    k++;
                }
                else if (sum == target)
                {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    // k++ & l--
                    int prevK = nums[k];
                    int prevL = nums[l];
                    if (nums[k] == prevK && k < l)
                    {
                        k++;
                    }
                    if (nums[l] == prevL && k < l)
                    {
                        l--;
                    }
                }
            }
        }
    }

    cout << "The 4 different numbers such that when added=" << target << " are: \n";
    for (auto row : ans)
    {
        for (auto it : row)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;
    // Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

    // fourSum_brute(arr, target);
    // fourSum_better(arr, target);
    fourSum_optimal(arr, target);

    return 0;
}