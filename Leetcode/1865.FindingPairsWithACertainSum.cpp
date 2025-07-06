#include <bits/stdc++.h>
using namespace std;

vector<int> arr1;
vector<int> arr2;
unordered_map<int, int> hashMap;
FindSumPairs(vector<int> &nums1, vector<int> &nums2)
{
    arr1 = nums1;
    arr2 = nums2;

    for (auto it : nums2)
    {
        hashMap[it]++;
    }
}

void add(int index, int val)
{
    // hash array
    hashMap[arr2[index]]--;
    arr2[index] += val;
    hashMap[arr2[index]]++;
}

int count(int tot)
{
    int ans = 0;
    // given that nums1 is smaller than nums2
    // loop thru array1 & find if complement exists in hashMap
    for (auto it : arr1)
    {
        int complement = tot - it;
        if (hashMap.find(complement) != hashMap.end())
        {
            // ie found!
            ans += hashMap[complement];
        }
    }
    // return count of pairs
    return ans;
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

int main()
{
    vector<int> nums1 = {1, 1, 2, 2, 2, 3};
    vector<int> nums2 = {1, 4, 5, 2, 5, 4};
    cout << "\nThe no of pairs that sum upto 7: " << count(nums1, nums2, 7);
    cout << "\nThe nums2 after 2 is added at index 3: " << add(nums2, 3, 2);
    return 0;
}