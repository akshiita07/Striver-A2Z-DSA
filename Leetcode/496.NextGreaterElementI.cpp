#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n1=nums1.size();
    int n2=nums2.size();
    vector<int> nums2NGE(n2,-1);
    // find NGE for nums2 array
    stack<int> st;
    for(int i=n2-1;i>=0;i--){
        while(st.empty()==false && st.top()<=nums2[i])
        {
            st.pop();
        }
        if(st.empty()){
            nums2NGE[i]=-1;
        }else{
            // nge found
            nums2NGE[i]=st.top();
        }
        // push this elem in stack
        st.push(nums2[i]);
    }
    // map elem from nums1 to nums2 to find NGE
    vector<int> ans(n1,-1);
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(nums1[i]==nums2[j]){
                // index of nums2:j
                ans[i]=nums2NGE[j];
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    // map nums1 elements to nums2
    // find NGE in nums2
    // give ans mapped to nums1
    // op:{-1,3,-1}
    vector<int> ans=nextGreaterElement(nums1,nums2);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}