// fabs(x) is the floating-point absolute value function in C++ (from <cmath>).
#include <bits/stdc++.h>
using namespace std;

const double mod = 1e-6;
bool solve(vector<double> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        // check if abs floating point value is equal to 24
        return fabs(nums[0] - 24) < mod;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            vector<double> next;
            for (int k = 0; k < n; k++)
            {
                if (k != i && k != j)
                {
                    next.push_back(nums[k]);
                }
            }
            // try all operations: +
            if (i < j)
            {
                next.push_back(nums[i] + nums[j]);
                if (solve(next))
                {
                    return true;
                }
                next.pop_back();
            }
            // try all operations: -
            next.push_back(nums[i] - nums[j]);
            if (solve(next))
            {
                return true;
            }
            next.pop_back();
            // try all operations: *
            if (i < j)
            {
                next.push_back(nums[i] * nums[j]);
                if (solve(next))
                {
                    return true;
                }
                next.pop_back();
            }
            // try all operations: / also avoid division by zero
            if (fabs(nums[j]) > mod)
            {
                next.push_back(nums[i] / nums[j]);
                if (solve(next))
                {
                    return true;
                }
                next.pop_back();
            }
        }
    }
    return false;
}

bool judgePoint24(vector<int> &cards)
{
    int n = 4; // length
    // 4 cards with number in [1, 9]
    // arrange numbers using operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24
    //  return true if u can get this expression else return false
    vector<double> nums(cards.begin(), cards.end());
    return solve(nums);
}

int main()
{
    vector<int> cards = {4, 1, 8, 7};
    cout << "\ncan get this expression as 24= " << judgePoint24(cards);

    return 0;
}