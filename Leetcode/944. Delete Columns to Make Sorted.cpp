class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int count = 0;

        for (int col = 0; col < m; col++) {
            for (int row = 1; row < n; row++) {
                if (strs[row][col] < strs[row - 1][col]) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
