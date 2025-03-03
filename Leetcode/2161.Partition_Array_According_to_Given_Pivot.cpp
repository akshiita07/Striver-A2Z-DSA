#include <bits/stdc++.h>
using namespace std;

vector<int> pivotArray(vector<int> &nums, int pivot)
{
    // elements less than pivot -- pivot -- elements greater than pivot
    vector<int> ans;
    vector<int> elementsSmallerThanPivot;
    vector<int> elementsLargerThanPivot;
    int countPivot = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < pivot)
        {
            elementsSmallerThanPivot.push_back(nums[i]);
        }
        else if (nums[i] > pivot)
        {
            elementsLargerThanPivot.push_back(nums[i]);
        }
        else if (nums[i] == pivot)
        {
            countPivot++;
        }
    }
    // now just form final array:
    for (int i = 0; i < elementsSmallerThanPivot.size(); i++)
    {
        ans.push_back(elementsSmallerThanPivot[i]);
    }
    while (countPivot > 0)
    {
        ans.push_back(pivot);
        countPivot--;
    }
    for (int i = 0; i < elementsLargerThanPivot.size(); i++)
    {
        ans.push_back(elementsLargerThanPivot[i]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;
    vector<int> ans = pivotArray(nums, pivot);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}