#include <bits/stdc++.h>
using namespace std;

// prefix max-> start from left & give maximum of elements from left--> left max
vector<int> prefixMax(vector<int> &height)
{
    // TIME: O(n)
    // Space: O(n)->to store array
    int n = height.size();
    vector<int> prefix(n);
    prefix[0] = height[0]; // 1st elem will be array's first
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], height[i]);
    }
    return prefix;
}
// suffix max-> start from right & give maximum of elements from right--> right max
vector<int> suffixMax(vector<int> &height)
{
    // TIME: O(n)
    // Space: O(n)->to store array
    int n = height.size();
    vector<int> suffix(n);
    suffix[n - 1] = height[n - 1]; // last elem will be array's last
    for (int i = n - 2; i >= 0; i--)
    { // traverse in backward direction
        suffix[i] = max(suffix[i + 1], height[i]);
    }
    return suffix;
}
// TIME: O(n+n)->to calculate prefix & suffix + O(n)->calculating total water == O(3n)
// SPACE: O(n+n)->to store prefix & suffix max
int bruteforce(vector<int> &height)
{
    vector<int> prefix = prefixMax(height);
    vector<int> suffix = suffixMax(height);

    int total = 0;
    int n = height.size();
    for (int i = 0; i < n; i++)
    {
        int leftMax = prefix[i];
        int rightMax = suffix[i];
        if (height[i] < leftMax && height[i] < rightMax)
        {
            // ie lies between 2 higher buildings so water log:
            total += min(leftMax, rightMax) - height[i];
        }
    }
    return total;
}

// optimize space:
// we always require smaller one out of left & right max: 2 pointer approach
int trap(vector<int> &height)
{
    // TIME: O(n)->while loop
    // SPACE: O(1)-> no extra space
    int n = height.size();
    int leftPtr = 0;
    int leftMax = 0;
    int rightPtr = n - 1;
    int rightMax = 0;
    int total = 0; // to cal total

    while (leftPtr < rightPtr)
    {
        if (height[leftPtr] <= height[rightPtr])
        {
            // go with left one
            if (leftMax > height[leftPtr])
            {
                // there is a building on left
                total += leftMax - height[leftPtr];
            }
            else
            {
                // not greater so update
                leftMax = height[leftPtr];
            }
            leftPtr += 1;
        }
        else
        {
            // go with right one
            if (rightMax > height[rightPtr])
            {
                // there is a building on left
                total += rightMax - height[rightPtr];
            }
            else
            {
                // not greater so update
                rightMax = height[rightPtr];
            }
            rightPtr -= 1;
        }
    }
    return total;
}

int main()
{
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; // 6
    cout << "\nBRUTE FORCE: The amount of water it can trap after raining1 is: " << bruteforce(height1);
    cout << "\nThe amount of water it can trap after raining1 is: " << trap(height1);

    vector<int> height2 = {4, 2, 0, 3, 2, 5}; // 9
    cout << "\nBRUTE FORCE: The amount of water it can trap after raining2 is: " << bruteforce(height2);
    cout << "\nThe amount of water it can trap after raining2 is: " << trap(height2);

    return 0;
}