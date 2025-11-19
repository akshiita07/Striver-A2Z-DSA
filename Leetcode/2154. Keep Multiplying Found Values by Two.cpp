class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        for (int i = 0; i < n; i++) {
            if (st.find(original) != st.end()) {
                // found original element:
                original *= 2;
            } else {
                return original;
            }
        }
        return original;
    }
};
