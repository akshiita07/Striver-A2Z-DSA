class Solution {
public:
    bool rotateString(string s, string goal) {
        // shift on string s consists of moving the leftmost character of s to the rightmost position
        // true if and only if string s can become string goal after some number of shifts on s
        if (s.length() != goal.length()) {
            // cannot be formed even after shifts:
            return false;
        }
        if (s == goal) {
            return true;
        }
        int n = s.length();
        for (int i = 0; i < n; i++) {
            // try all possible shifts & compare each time with GOAL:
            char leftmostChar = s[0];
            // erase the first character
            s.erase(s.begin());
            // add it at end
            s.push_back(leftmostChar);

            if (s == goal) {
                return true;
            }
        }
        // not possible then
        return false;
    }
};
