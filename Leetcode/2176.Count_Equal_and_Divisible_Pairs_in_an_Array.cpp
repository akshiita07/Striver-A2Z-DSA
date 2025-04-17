#include <bits/stdc++.h>
using namespace std;

int brute_force(vector<int> &nums, int k)
{
    int n = nums.size();
    // return number of pairs (i, j) where 0 <= i < j < n, st nums[i] == nums[j] and (i * j) is divisible by k
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == nums[j] && (i * j) % k == 0)
            {
                count++;
            }
        }
    }
    return count;
}

int countPairs(vector<int> &nums, int k)
{
    int n = nums.size();
    // return number of pairs (i, j) where 0 <= i < j < n, st nums[i] == nums[j] and (i * j) is divisible by k
    int count = 0;
    // take a hashmap with number and its list of indices
    unordered_map<int, vector<int>> hashMap;
    for (int i = 0; i < n; i++)
    {
        hashMap[nums[i]].push_back(i);
    }
    // iterate thru hashmap to check conditions:
    for (auto it : hashMap)
    {
        int len = it.second.size();
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if ((it.second[i] * it.second[j]) % k == 0)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{
    vector<int> nums = {3, 1, 2, 2, 2, 1, 3};
    int k = 2;
    cout << "\nbrute_force:number of pairs (i,j) = " << brute_force(nums, k);
    cout << "\nnumber of pairs (i,j) = " << countPairs(nums, k);

    return 0;
}