#include <bits/stdc++.h>
using namespace std;

// TIME: O(n^2)
// SPACE: O(n)->to return answer NOT TO SOLVE PROBLEM
vector<int> brute_force(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    // for i=0: always -1:
    // ans[0]=-1;
    for (int i = 0; i < n; i++)
    {
        // check left elements
        for (int j = i - 1; j >=0; j--)
        {
            // smaller element
            if (arr[j] < arr[i])
            {
                ans[i] = (arr[j]);
                break; // as we need only 1st greater
            }
        }
    }
    return ans;
}

// optimise time complexity:
// TIME: O(2n)->worst case 
// for loop:O(n) but while loop does NOT run for n times-->st.pop can work for at max n elements NOT more-->O(2n)
// SPACE: O(n)->vector ans + O(n)--> stack
vector<int> nextSmallerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st; // monotonic stack that stores elements in INCREAsing order

    // start iterating from start of array
    for (int i = 0; i <n; i++)
    {
        // pop elements until a greater elem is found:
        while (st.empty() == false && st.top() >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            // no NGE so -1
            ans[i]=-1;
        }
        else if (st.top() < arr[i])
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
    vector<int> arr = {4,5,2,10,8};
    // output array must contain next smaller elements towards LEFT ie {-1,4,-1,2,2}
    // vector<int> ans = brute_force(arr);
    vector<int> ans = nextSmallerElement(arr);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}