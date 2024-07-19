#include <bits/stdc++.h>
using namespace std;
// find 3 different numbers such that when added=0

// BRUTE FORCE: TIME-O(n^3)     SPACE:O(n)->temp
void threeSum_brute(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
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

    cout << "The 3 different numbers such that when added=0 are: \n";
    for (auto row : ans)
    {
        for (auto it : row)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}

// BETTER:HASH SET TIME-O(n^2)      SPACE:2O(n)->set+temp array
void threeSum_better(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n - 1; i++)
    {
        set<int> hashSet; // only unique
        for (int j = i + 1; j < n; j++)
        {

            int k = -(nums[i] + nums[j]);
            // check if arr[k] exists in set
            if (hashSet.find(k) != hashSet.end())
            {
                // found in map
                vector<int> temp = {nums[i], nums[j], k};
                sort(temp.begin(), temp.end());
                if (find(ans.begin(), ans.end(), temp) == ans.end())
                {
                    // ie not found then add
                    ans.push_back(temp);
                }
            }
            else
            {
                // does not exist
                hashSet.insert(nums[j]);
            }
        }
    }

    cout << "The 3 different numbers such that when added=0 are: \n";
    for (auto row : ans)
    {
        for (auto it : row)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}

// OPTIMAL:2POINTER      TIME-O(nlogn)->sort array +O(n)->i loop +O(n)->while loop so time:O(n^2)      SPACE:O(1)->no extra space reqd
void threeSum_optimal(vector<int> &nums)
{
    sort(nums.begin(), nums.end()); // sort array

    int n = nums.size();
    vector<vector<int>> ans;

    // if j crosses k then i++
    for (int i = 0; i < n; i++)
    {
        // for same value of i keep moving it
        if (nums[i] == nums[i - 1] && i > 0)
        {
            continue;
            // ie do i++
        }
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            if (nums[i] + nums[j] + nums[k] == 0)
            {
                int prevJ = nums[j];
                int prevK = nums[k];
                ans.push_back({nums[i], nums[j], nums[k]});
                while (nums[j] == prevJ && j<k)
                {
                    j++;
                }
                while (nums[k] == prevK && j<k)
                {
                    k--;
                }
            }
            else if (nums[i] + nums[j] + nums[k] < 0)
            {
                // lesser than 0 so move j
                int prevJ = nums[j];
                while (nums[j] == prevJ && j<k)
                {
                    j++;
                }
            }
            else if (nums[i] + nums[j] + nums[k] > 0)
            {
                // greater than 0 so movek
                int prevK = nums[k];
                while (nums[k] == prevK && j<k)
                {
                    k--;
                }
            }
        }
    }

    cout << "The 3 different numbers such that when added=0 are: \n";
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
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    // Output: [[-1,-1,2],[-1,0,1]]

    // threeSum_brute(arr);
    // threeSum_better(arr);
    threeSum_optimal(arr);

    return 0;
}