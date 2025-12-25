class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        // select k from n children
        // if child not selected and its happiness[i] is positive then decreent it by 1... cannot be -ve
        // return max sum of happiness values of selected children
        // sort happiness in decreasing order
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long ans=0;
        for(int i=0;i<k;i++){
            ans+=max(happiness[i]-i,0);
        }
        return ans;
    }
};
