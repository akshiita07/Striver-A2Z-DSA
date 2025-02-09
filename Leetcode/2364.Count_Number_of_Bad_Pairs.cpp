#include <bits/stdc++.h>
using namespace std;

long long brute_force(vector<int> &nums)
{
    int n = nums.size();
    long long count = 0;
    // pair (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i]
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j && (j - i) != nums[j] - nums[i])
            {
                count++;
            }
        }
    }
    return count;
}

long long countBadPairs(vector<int> &nums)
{
    int n = nums.size();
    long long goodPairs = 0;
    unordered_map<int, int> hashMap; // stores diff->count
    // pair (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i]
    // rephrame: nums[i] - i != nums[j] - j
    for (int i = 0; i < n; i++)
    {
        int diff = nums[i] - i;
        goodPairs += hashMap[diff]; // when both diff[i]==diff[j] then good pair
        hashMap[diff]++;
    }
    long long totalPairs = ((1LL * n * (n - 1)) / 2);
    long long badPairs = 1LL * (totalPairs - goodPairs);
    return badPairs;
}

int main()
{
    vector<int> nums = {4, 1, 3, 3};
    cout << "\nThe total number of bad pairs in nums= " << countBadPairs(nums);

    return 0;
}