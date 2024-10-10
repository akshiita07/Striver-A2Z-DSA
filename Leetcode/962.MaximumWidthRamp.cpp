#include <bits/stdc++.h>
using namespace std;

int maxWidthRamp(vector<int> &nums)
{
    // pair (i,j)
    // where i<j
    // nums[i]<=nums[j]
    // return max possible ramp ie j-i
    stack<int> st;
    for(int i=0;i<nums.size();i++){
        if(st.empty() || nums[st.top()]>nums[i]){
            // num[top elem]>num[current]
            st.push(i);
        }
    }

    int maxRamp=0;
    // traverse from end:
    for(int i=nums.size()-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]<=nums[i]){
            maxRamp=max(maxRamp,i-st.top());
            st.pop();
        }
    }

    return maxRamp;
}

int main()
{
    vector<int> nums = {6, 0, 8, 2, 1, 5};
    cout << "\nThe ramp is: " << maxWidthRamp(nums);

    return 0;
}