#include <bits/stdc++.h>
using namespace std;

bool canDistribute(vector<int> &candies, long long k, int mid)
{
    if (mid == 0)
    {
        return false; // Avoid division by zero
    }
    long long count = 0;
    for (auto c : candies)
    {
        count += (c / mid); // How many piles of 'mid' can we form?
        if (count >= k)
            return true; // If we can satisfy k children, return true
    }
    return false;
}
int maximumCandies(vector<int> &candies, long long k)
{
    int left = 1;
    int right = *max_element(candies.begin(), candies.end());
    int ans = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (canDistribute(candies, k, mid))
        {
            ans = mid;      // Store the valid mid
            left = mid + 1; // Try for a larger value
        }
        else
        {
            right = mid - 1; // Reduce max value
        }
    }
    return ans;
}

int main()
{

    return 0;
}