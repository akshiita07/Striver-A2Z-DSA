#include <bits/stdc++.h>
using namespace std;

vector<bool> prefixesDivBy5(vector<int> &nums)
{
    // xi: number whose binary representation is the subarray nums[0..i]
    vector<bool> ans;
    // answer[i] is true if xi is divisible by 5
    int n = nums.size();
    int mod = 0;

    for (int i = 0; i < n; i++)
    {
        mod = (mod * 2 + nums[i]) % 5;
        if (mod == 0)
        {
            ans.push_back(true);
        }
        else
        {
            ans.push_back(false);
        }
    }
    return ans;
}

int main()
{

    return 0;
}