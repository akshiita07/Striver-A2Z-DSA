#include <bits/stdc++.h>
using namespace std;

// TIME: O(n^2)
// SPACE: O(n)->to return answer
vector<int> brute_force(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        // circular array: j goes till i+n-1
        for (int j = i + 1; j < i + n; j++)
        {
            int index = j % n; // index%size
            if (arr[index] > arr[i])
            {
                ans[i] = (arr[index]);
                break; // as we need only 1st greater
            }
        }
    }
    return ans;
}

// optimize time:   MONTONIC STACK
// TIME: O(2*n):for loop + O(2n):removing 2n elemen at max can be removed == O(4*n)
// SPACE: O(n)->vector for returning ans + O(2n)->stack == O(3n)
vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);
    // for last element of nums...search for NGE in stack again
    stack<int> st;

    // start traversing from hypothetical double array end ie 2n-1
    for (int i = (2 * n) - 1; i >= 0; i--)
    {
        while (st.empty() == false && st.top() <= nums[i % n])
        {
            st.pop();
        }
        if (i >= n)
        {
            // we do not require NGE
        }
        else
        {
            // i<n:
            // no requirement of i%size as i<n in this case
            if (st.empty())
            {
                ans[i] = -1;
            }
            else
            {
                // top>nums[i]
                ans[i] = st.top();
            }
        }
        // push new
        st.push(nums[i%n]);
    }
    // for last element search in stack:
    while (st.empty() == false && st.top() <= nums[n - 1])
    {
        st.pop();
    }
    if (st.empty())
    {
        ans[n - 1] = -1;
    }
    else
    {
        // top>nums[i]
        ans[n - 1] = st.top();
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 3};
    // nums1 is circularly connected!
    // find NGE of all elements else return -1
    // op:{2,3,4,-1,4}
    // vector<int> ans = brute_force(nums);
    vector<int> ans = nextGreaterElements(nums);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}