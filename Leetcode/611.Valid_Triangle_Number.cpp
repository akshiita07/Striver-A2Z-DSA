#include <bits/stdc++.h>
using namespace std;

int brute_force(vector<int> &nums)
{
    // a+b>c
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if ((nums[i] + nums[j] > nums[k]) && (nums[j] + nums[k] > nums[i]) && (nums[i] + nums[k] > nums[j]))
                {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int triangleNumber(vector<int> &nums)
{
    // a+b>c
    int n = nums.size();
    int cnt = 0;
    sort(nums.begin(), nums.end());
    for (int i = n - 1; i >= 2; i--)
    {
        int j = 0;
        int k = i - 1;
        while (j < k)
        {
            if (nums[j] + nums[k] > nums[i])
            {
                cnt += k - j;
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return cnt;
}

int main()
{

    return 0;
}