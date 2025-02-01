#include <bits/stdc++.h>
using namespace std;

bool isArraySpecial(vector<int> &nums)
{
    // adjacent elements contains two numbers with different parity
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        int firstNum = nums[i];
        int secNum = nums[i + 1];
        // first odd then second even OR first even second odd
        if ((firstNum % 2 != 0 && secNum % 2 == 0) || (firstNum % 2 == 0 && secNum % 2 != 0))
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> nums1 = {4, 3, 1, 6};
    cout << "\nNums1 is a special array= " << isArraySpecial(nums1);
    vector<int> nums2 = {2, 1, 4};
    cout << "\nNums2 is a special array= " << isArraySpecial(nums2);

    return 0;
}