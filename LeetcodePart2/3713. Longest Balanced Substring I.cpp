class Solution {
public:
    bool isBalanced(unordered_map<char, int>& hashMap) {
        int cnt = -1;
        for (auto it : hashMap) {
            if (cnt == -1) {
                cnt = it.second;
            } else if (cnt != it.second) {
                return false;
            }
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> hashMap;
            for (int j = i; j < n; j++) {
                hashMap[s[j]]++;
                if (isBalanced(hashMap)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
