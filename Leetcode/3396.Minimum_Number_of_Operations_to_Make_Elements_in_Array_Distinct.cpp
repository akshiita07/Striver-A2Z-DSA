#include <bits/stdc++.h>
using namespace std;

bool checkIfDistinct(unordered_map<int, int> &hashMap)
{
    // check if the elements in array are distinct
    for (auto it : hashMap)
    {
        if (it.second > 1)
        {
            return false;
        }
    }
    return true;
}

int minimumOperations(vector<int> &nums)
{
    int n = nums.size();
    // elements in array must be distinct
    // remove 3 elements from beginning of array (if fewer than 3 elements in array then remove all & empty array is also distinct)
    unordered_map<int, int> hashMap;
    for (int i = 0; i < n; i++)
    {
        hashMap[nums[i]]++;
    }
    int count = 0; // min no of times operation is performed
    while (!checkIfDistinct(hashMap))
    {

        for (int i = 0; i < 3 && !nums.empty(); i++)
        {
            int front = nums.front();
            hashMap[front]--;
            if (hashMap[front] == 0)
            {
                hashMap.erase(front);
            }
            nums.erase(nums.begin());
        }
        count++;
    }
    return count;
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 2, 3, 3, 5, 7};
    cout << "\nMinimum Number of Operations to Make Elements in Array Distinct: " << minimumOperations(nums);
    return 0;
}