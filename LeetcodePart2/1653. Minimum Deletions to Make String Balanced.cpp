class TLESolution {
public:
    int findAAfter(string s, int endIdx) {
        int cnt = 0;
        int n = s.length();
        for (int i = endIdx; i < n; i++) {
            if (s[i] == 'a') {
                cnt++;
            }
        }
        return cnt;
    }
    int findBBefore(string s, int endIdx) {
        int cnt = 0;
        for (int i = 0; i < endIdx; i++) {
            if (s[i] == 'b') {
                cnt++;
            }
        }
        return cnt;
    }
    int minimumDeletions(string s) {
        int n = s.length();
        if (n == 1) {
            return 0;
        }
        // s consists of a & n
        // min no of chars to delete so that all a first then all b
        // for every index find no of a's before & no of b's after
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            int aAfter = findAAfter(s, i);
            int bBefore = findBBefore(s, i);
            ans = min(ans, aAfter + bBefore);
        }
        return ans;
    }
};
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        // s consists of a & n
        // min no of chars to delete so that all a first then all b
        // for every index find no of a's before & no of b's after
        int noOfA = 0;
        for (auto it : s) {
            if (it == 'a') {
                noOfA++;
            }
        }
        int noOfB = 0;
        int noOfALeft = noOfA;
        int ans = noOfALeft;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                noOfALeft--; // a remaining on right to be deleted
            } else {
                noOfB++;    // b's on left
            }
            ans = min(ans, noOfALeft + noOfB);
        }
        return ans;
    }
};
