#include <bits/stdc++.h>
using namespace std;

// TIME: O(n^2)
// SPACE: O(1)
long long bruteforce(vector<int> &nums)
{
    int n = nums.size();
    long long sumOfRanges = 0;
    // find all subnumsays
    for (int i = 0; i < n; i++)
    {
        int minElem = nums[i];
        int maxElem = nums[i];
        for (int j = i; j < n; j++)
        {
            // find min of all subnumsays
            minElem = min(minElem, nums[j]);
            // find max of all subnumsays
            maxElem = max(maxElem, nums[j]);
            // find range
            long long range = maxElem - minElem;
            sumOfRanges += range;
        }
    }
    // find sum of ranges
    return sumOfRanges;
}

// TIME: O()
// SPACE: O()
vector<int> next_smaller_index(vector<int> &nums)
{
    // store INDEX in stack (not elements)
    stack<int> st;
    int n = nums.size();
    vector<int> nse(n);
    // start from back
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.empty() == false && nums[st.top()] >= nums[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            nse[i] = n;
        }
        else
        {
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
}
// find previous smaller OR equal!!
vector<int> previous_smaller_index(vector<int> &nums)
{
    // store INDEX in stack (not elements)
    stack<int> st;
    int n = nums.size();
    vector<int> pse(n);
    // start from front
    for (int i = 0; i < n; i++)
    {
        while (st.empty() == false && nums[st.top()] > nums[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            pse[i] = -1;
        }
        else
        {
            pse[i] = st.top();
        }
        st.push(i);
    }
    return pse;
}
// for max:
vector<int> next_greater_index(vector<int> &nums)
{
    // store INDEX in stack (not elements)
    stack<int> st;
    int n = nums.size();
    vector<int> nge(n);
    // start from back
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.empty() == false && nums[st.top()] <= nums[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            nge[i] = n;
        }
        else
        {
            nge[i] = st.top();
        }
        st.push(i);
    }
    return nge;
}
// find previous greater OR equal!!
vector<int> previous_greater_index(vector<int> &nums)
{
    // store INDEX in stack (not elements)
    stack<int> st;
    int n = nums.size();
    vector<int> pge(n);
    // start from front
    for (int i = 0; i < n; i++)
    {
        while (st.empty() == false && nums[st.top()] < nums[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            pge[i] = -1;
        }
        else
        {
            pge[i] = st.top();
        }
        st.push(i);
    }
    return pge;
}

long long minSumOfSubarrays(vector<int> &nums)
{
    long long sum = 0;
    vector<int> nsi = next_smaller_index(nums);     // TIME: O(2n)   SPACE:O(n)->stack
    vector<int> psi = previous_smaller_index(nums); // TIME: O(2n)   SPACE:O(n)->stack
    for (int i = 0; i < nums.size(); i++)
    {
        // no of elemen on left
        int noElemOnLeft = i - psi[i];
        // no of elemen on right
        int noElemOnRight = nsi[i] - i;
        long long prod = (long long)(noElemOnLeft * noElemOnRight);
        sum = sum + (prod * nums[i]);
    }
    return sum;
}

long long maxSumOfSubarrays(vector<int> &nums)
{
    long long sum = 0;
    vector<int> ngi = next_greater_index(nums);     // TIME: O(2n)   SPACE:O(n)->stack
    vector<int> pgi = previous_greater_index(nums); // TIME: O(2n)   SPACE:O(n)->stack
    for (int i = 0; i < nums.size(); i++)
    {
        // no of elemen on left
        int noElemOnLeft = i - pgi[i];
        // no of elemen on right
        int noElemOnRight = ngi[i] - i;
        long long prod = (long long)(noElemOnLeft * noElemOnRight);
        sum = sum + (prod * nums[i]);
    }
    return sum;
}

long long subArrayRanges(vector<int> &nums)
{
    return (long long)(maxSumOfSubarrays(nums) - minSumOfSubarrays(nums));
}

int main()
{
    vector<int> nums = {1, 2, 3}; // 4
    cout << "\nBRUTE FORCE-> The sum of MINIMUM of all possible subarrays of nums is: " << bruteforce(nums);
    cout << "\nThe sum of MINIMUM of all possible subarrays of nums is: " << subArrayRanges(nums);

    return 0;
}