#include <bits/stdc++.h>
using namespace std;

vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
{
    // perform operation k times:
    // find 1st min value of nums
    // replace it with nums*multiplier
    int n = nums.size();
    while (k > 0)
    {
        int minEle = nums[0];
        int minIndx = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < minEle)
            {
                minEle = nums[i];
                minIndx = i;
            }
        }
        nums[minIndx] = multiplier * nums[minIndx];
        k--;
    }
    return nums;
}

int main()
{
    vector<int> nums = {2, 1, 3, 5, 6};
    int k = 5;
    int multiplier = 2;
    vector<int> ans = getFinalState(nums, k, multiplier);
    cout << "Ans:\n";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}