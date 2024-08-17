#include <bits/stdc++.h>
using namespace std;

// TIME: O(n^2)
// SPACE: O(n)->to return answer NOT TO SOLVE PROBLEM
vector<int> brute_force(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                ans[i] = (arr[j]);
                break; // as we need only 1st greater
            }
        }
        // if (ans.size()<i+1)
        // {
        //     ans.push_back(-1);
        // }
    }
    return ans;
}

// optimise time complexity:
// TIME: O(2n)->worst case 
// for loop:O(n) but while loop does NOT run for n times-->st.pop can work for at max n elements NOT more-->
// SPACE: O(n)->vector ans + O(n)--> stack
vector<int> nextGreaterElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st; // monotonic stack that stores elements in decreasing order

    // start iterating from back of array
    for (int i = n - 1; i >= 0; i--)
    {
        // pop elements until a greater elem is found:
        while (st.empty() == false && st.top() <= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            // no NGE so -1
            ans[i]=-1;
        }
        else if (st.top() > arr[i])
        {
            // it is NGE
            ans[i] = st.top();
        }
        // after this push current element inside stack:
        st.push(arr[i]);
    }
    return ans;
}

int main()
{
    vector<int> arr = {6, 0, 8, 1, 3};
    // output array must contain next greater elements ie {8,8,-1,3,-1}
    // vector<int> ans = brute_force(arr);
    vector<int> ans = nextGreaterElement(arr);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}