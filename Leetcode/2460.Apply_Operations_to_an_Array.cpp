#include <bits/stdc++.h>
using namespace std;

vector<int> applyOperations(vector<int> &nums)
{
    int n = nums.size();
    // apply n-1 operations
    // If nums[i] == nums[i + 1]: multiply nums[i] by 2 and set nums[i + 1] to 0 Otherwise skip
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }
    //  shift all the 0's to the end of the array
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] != 0)
                {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
        }
    }
    return nums;
}

int main()
{
    vector<int> nums = {1, 2, 2, 1, 1, 0};
    vector<int> ans = applyOperations(nums);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}