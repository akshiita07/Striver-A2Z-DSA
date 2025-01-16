#include <bits/stdc++.h>
using namespace std;

int brute_force(vector<int> &nums1, vector<int> &nums2)
{
    int bitwiseXorOfNums3 = 0;
    vector<int> nums3; // contains bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once)
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            nums3.push_back(nums1[i] ^ nums2[j]);
        }
    }
    for (int i = 0; i < nums3.size(); i++)
    {
        bitwiseXorOfNums3 ^= nums3[i];
    }
    return bitwiseXorOfNums3;
}

int xorAllNums(vector<int> &nums1, vector<int> &nums2)
{
    int bitwiseXorOfNums3 = 0;
    int xorNums1 = 0;
    int xorNums2 = 0;
    for (int i = 0; i < nums1.size(); i++)
    {
        xorNums1 ^= nums1[i];
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        xorNums2 ^= nums2[i];
    }
    if (nums1.size() % 2 != 0)
    {
        // will contribute each elem of nums2:
        bitwiseXorOfNums3 ^= xorNums2;
    }
    if (nums2.size() % 2 != 0)
    {
        // will contribute each elem of nums1:
        bitwiseXorOfNums3 ^= xorNums1;
    }
    return bitwiseXorOfNums3;
}

int main()
{
    vector<int> nums1 = {2, 1, 3};
    vector<int> nums2 = {10, 2, 5, 0};
    cout << "\nbrute_force Bit wise xor of numbers in nums3 is: " << brute_force(nums1, nums2);
    cout << "\nBit wise xor of numbers in nums3 is: " << xorAllNums(nums1, nums2);

    return 0;
}