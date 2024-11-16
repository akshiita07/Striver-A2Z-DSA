#include <bits/stdc++.h>
using namespace std;

vector<int> resultsArray(vector<int> &nums, int k)
{
    int n = nums.size();
    // power of an array-Its maximum element if all its elements r consecutive & sorted in ascending order -> -1 otherwise.
    // find the power of all  subarrays of nums of size k

    // Return an integer array results of size n - k + 1,
    //  results[i] is the power of nums[i..(i + k - 1)]
    vector<int> result;

    for (int i = 0; i <= n-k; i++)
    {
        bool isConsecutive = true;
        bool isSorted = true;

        if (is_sorted(nums.begin() + i, nums.begin() + i + k))
        {
            for (int j = i; j < (i + k - 1); j++)
            {
                // check from i to j if sorted + consecutive
                if (nums[j + 1] != nums[j] + 1)
                {
                    isConsecutive = false;
                    break;
                }
            }
        }else{
            isSorted = false;
        }

        if (isConsecutive && isSorted)
        {
            int maxEle =*max_element(nums.begin()+i,nums.begin()+i+k);
            result.push_back(maxEle);
        }
        else
        {
            result.push_back(-1);
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 3, 2, 5};
    int k = 3;
    vector<int> result = resultsArray(nums, k);
    cout << "Power array: \n";
    for (auto it : result)
    {
        cout << it << " ";
    }

    return 0;
}