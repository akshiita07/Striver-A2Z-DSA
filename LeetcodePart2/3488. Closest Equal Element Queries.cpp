//TLE:
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n1 = queries.size();
        int n2 = nums.size();
        vector<int> ans(n1, -1);
        // for each query:
        for (int i = 0; i < n1; i++) {
            int minDist = INT_MAX;
            // find closest in circular array nums:
            int target = nums[queries[i]];
            int startIndex = queries[i];
            for (int j = 0; j < n2; j++) {
                //cannot check for same element so:
                if(j==startIndex){
                    continue;
                }
                if (nums[j] == target) {
                    // found:
                    int d = abs(startIndex - j);
                    d = min(d, n2 - d);
                    minDist = min(minDist, d);
                }
            }
            if (minDist != INT_MAX) {
                ans[i] = minDist;
                //else keep -1 only
            }
        }
        return ans;
    }
};
