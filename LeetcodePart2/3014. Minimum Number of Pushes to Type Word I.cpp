class Solution {
public:
    int minimumPushes(string word) {
        // min no of pushes at key no: 2,3,4,5,6,8 and at 1st position
        //  8 distinct keys available
        int n = word.length();
        // if (n <= 8) {
        //     return n;
        // }
        // // if more than 8 characters:
        // int remaining = n - 8;
        // if (remaining > 8) {
        //     // next remaining loop
        //     int nextRemaining = remaining - 8;
        //     return 3 * nextRemaining + 16 + 8;
        // }
        // return 2 * remaining + 8;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += i / 8 + 1;
        }
        return ans;
    }
};
