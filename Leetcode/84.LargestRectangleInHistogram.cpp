#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &heights)
{
    int n = heights.size();
    vector<int> nse(n);
    stack<int> st;
    // store indices (not elements)
    // loop from back
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.empty() == false && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            nse[i] = n; // till max index n
        }
        else
        {
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
}
vector<int> previousSmallerElement(vector<int> &heights)
{
    int n = heights.size();
    vector<int> pse(n);
    stack<int> st;
    // store indices (not elements)
    for (int i = 0; i < n; i++)
    {
        while (st.empty() == false && heights[st.top()] >= heights[i])
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
// TIME: O(2n)->for nse + O(2n)->for pse + O(n)->for loop == O(5n)
// SPACE: O(n)->nse stack + O(n)->pse stack + O(2n)->2vectors for nse&pse == O(4n)
int bruteforce(vector<int> &heights)
{
    // maintain list of all possible max areas
    vector<int> areas;
    int n = heights.size();
    if (n == 1)
    {
        // only 1 element
        return heights[0];
    }
    vector<int> pse = previousSmallerElement(heights);
    vector<int> nse = nextSmallerElement(heights);
    for (int i = 0; i < n; i++)
    {
        // find pse & nse ka index
        int prevSmallIndex = pse[i];
        int nextSmallIndex = nse[i];
        int width = nextSmallIndex - prevSmallIndex - 1;
        areas.push_back(width * heights[i]);
    }
    // return max of these all areas
    return *max_element(areas.begin(), areas.end());
}

// TIME: O(n)->for loop + O(n)->popping atmax n elements == O(2n)
// SPACE: O(n)->stack
int largestRectangleArea(vector<int> &heights)
{
    // find nse & pse in single pass:
    int maxArea = 0;
    stack<int> st; // stores index
    int n = heights.size();
    if (n == 1)
    {
        // only 1 element
        return heights[0];
    }
    for (int i = 0; i < n; i++)
    {
        while (st.empty() == false && heights[st.top()] > heights[i])
        {
            int elem = st.top();
            st.pop();
            int nse = i;
            int pse;
            if (st.empty() == false)
            {
                pse = st.top();
            }
            else
            {
                pse = -1;
            }
            maxArea = max(maxArea, ((nse - pse - 1) * heights[elem]));
        }
        // check if pse exists in stack
        // add new element as PSE exists
        st.push(i);
    }
    // for remaining elements
    while (st.empty() == false)
    {
        int elem = st.top();
        st.pop();
        int nse = n; // when nse does not exists
        int pse;
        if (st.empty() == false)
        {
            pse = st.top();
        }
        else
        {
            pse = -1;
        }
        maxArea = max(maxArea, ((nse - pse - 1) * heights[elem]));
    }
    return maxArea;
}

int main()
{
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    cout << "\n1:BRUTE FORCE--> The largest area of rectangle is: " << bruteforce(heights1);
    cout << "\n1:The largest area of rectangle is: " << largestRectangleArea(heights1);
    vector<int> heights2 = {0, 9};
    cout << "\n2:BRUTE FORCE--> The largest area of rectangle is: " << bruteforce(heights2);
    cout << "\n2:The largest area of rectangle is: " << largestRectangleArea(heights2);

    return 0;
}