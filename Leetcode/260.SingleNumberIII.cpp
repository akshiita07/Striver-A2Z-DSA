#include <bits/stdc++.h>
using namespace std;

// TIME: O(n*1)+O(n*1)==O(2n) where unordered map takes O(1)
// SPACE: O(n)->for map + O(2)->to return vector as ans
void brute_force(vector<int> &nums)
{
    vector<int> ans;
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
            ans.push_back(it.first);
        }
    }
    // return ans;
    cout << "\nPrinting elements that appear exactly once: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

void singleNumber(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();

    long xorAns = 0;
    // find xor of all elements of array
    for (int i = 0; i < n; i++)
    {
        xorAns = xorAns^nums[i];
    }
    // take right bit
    int right = (xorAns&(xorAns-1)) ^ xorAns;
    // take 2 buckets
    int b1 = 0;
    int b2 = 0;
    // loop
    for (int i = 0; i < n; i++)
    {
        if (nums[i] & right)
        {
            b1 = b1 ^ nums[i];
        }
        else
        {
            b2 = b2 ^ nums[i];
        }
    }
    ans.push_back(b1);
    ans.push_back(b2);
    // return ans;
    cout << "\nPrinting elements that appear exactly once: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

int main()
{
    // every element appears 2 times except 2 elements that appear only 1
    // return these 2 elements that appears only once!!
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    cout << "\nBRUTE FORCE: The no that appears exactly once are: ";
    brute_force(nums);

    cout << "\nThe no that appears exactly once are: ";
    singleNumber(nums);

    return 0;
}