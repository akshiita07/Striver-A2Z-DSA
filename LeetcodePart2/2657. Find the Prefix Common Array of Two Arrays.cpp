class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        // C:prefix common array where C[i] is equal to the count of numbers
        // that are present AT or BEFORE the index i in both A and B
        unordered_map<int, int> hashMap;
        vector<int> ans;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            hashMap[A[i]]++;
            hashMap[B[i]]++;
            // now check if its count is 2 then add to ans
            if (hashMap[A[i]] == 2) {
                // occurred in both A & B:
                cnt++;
            }
            if (A[i] != B[i] && hashMap[B[i]] == 2) {
                // occurred in both A & B:
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
