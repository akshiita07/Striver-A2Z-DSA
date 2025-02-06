#include <bits/stdc++.h>
using namespace std;

int tupleSameProduct(vector<int> &nums)
{
    // no of tuples (a, b, c, d) st a*b=c*d and a!=b!=c!=d
    // for each tuple (a,b,c,d) we have 8 possibilities of interchanging & writing
    int count = 0;
    // check all products formed & count the frequency of occurrence of a product:
    int n = nums.size();
    unordered_map<int, int> hashMap;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int product = nums[i] * nums[j];
            hashMap[product]++; // inc count:
        }
    }
    // traverse & check how many products occur for 2/more times:
    for (auto it : hashMap)
    {
        if (it.second >= 2)
        {
            count += 8 * ((it.second) * (it.second - 1) / 2);
        }
    }
    return count;
}

int main()
{
    // vector<int> nums = {2, 3, 4, 6}; // 8
    vector<int> nums = {1, 2, 4, 5, 10}; // 16
    cout << "\nNo of tuples= " << tupleSameProduct(nums);

    return 0;
}