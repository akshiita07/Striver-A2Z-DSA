#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        // 2 pointers:
        int i = 0;
        int j = n - 1;
        int maxWater = INT_MIN;
        while (i < j)
        {
            // area: min(height[i],height[j])*(j-i)
            maxWater = max(maxWater, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return maxWater;
    }
};