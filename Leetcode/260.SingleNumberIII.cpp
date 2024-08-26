#include <bits/stdc++.h>
using namespace std;

int brute_force(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> hashMap(0); // stores number and its count
    for (int i = 0; i < n; i++)
    {
        hashMap[nums[i]]++;
    }
    for (auto it : hashMap)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
}

vector<int> better_1(vector<int>& nums) {
        
    }

vector<int> better_2(vector<int>& nums) {
        
    }

vector<int> singleNumber(vector<int>& nums) {
        
    }

int main()
{
    // every element appears 3 times except 1
    // return element that appears only once!!
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
    cout << "\nBRUTE FORCE: The no that appears exactly once is: " << brute_force(nums);
    cout << "\nBETTER 1: The no that appears exactly once is: " << better_1(nums);
    cout << "\nBETTER 2: The no that appears exactly once is: " << better_2(nums);
    cout << "\nThe no that appears exactly once is: " << singleNumber(nums);

    return 0;
}