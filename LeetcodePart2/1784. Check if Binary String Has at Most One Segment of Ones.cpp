class Solution {
public:
    bool checkOnesSegment(string s) {
        // count no of 1s with no adjacent 1:
        int n = s.length();
        for (int i = 1; i < n; i++) {
            if (s[i] == '1' && s[i - 1] == '0') {
                return false;
            }
        }
        return true;
    }
};
