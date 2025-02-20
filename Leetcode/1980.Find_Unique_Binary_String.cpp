#include <bits/stdc++.h>
using namespace std;

// Cantor’s Diagonalization Method
string findDifferentBinaryString(vector<string> &nums)
{
    // n:no of strings each of length n
    // return binary string of length  n that deos NOT appear in nums
    int n = nums.size();
    string ans = "";
    // take diagonal element of each string & flip its bit:
    for (int i = 0; i < n; i++)
    {
        // if diagonal bit is 0 then add 1 to ans else add 0
        ans += nums[i][i] == '0' ? '1' : '0';
    }
    return ans;
}

int main()
{
    vector<string> nums = {"01", "10"};
    cout << "\nString not in nums is: " << findDifferentBinaryString(nums);

    return 0;
}