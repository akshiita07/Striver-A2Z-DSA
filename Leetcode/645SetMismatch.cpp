#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n=nums.size();
        // repeat,missing
        vector<int> ans(2);
        long long x=0;        //repeat
        long long y=0;        //missing

        long long sumN=(n*(n+1))/2;
        long long sum2N=(n*(n+1)*(2*n+1))/6;
        long long sumArr=0;
        long long sumSquare=0;
        for(int i=0;i<n;i++){
            sumArr+=nums[i];
            sumSquare+=(long long)nums[i]*(long long)nums[i];
        }

        // equations:
        long long eq1=sumArr-sumN;        //x-y=eq1
        long long eqAux=sumSquare-sum2N;      //x2-y2=eqAux
        long long eq2=eqAux/eq1;        //x+y=eq2

        x=(eq1+eq2)/2;
        y=eq2-x;

        ans[0]=int(x);
        ans[1]=int(y);
        return ans;
    }
};