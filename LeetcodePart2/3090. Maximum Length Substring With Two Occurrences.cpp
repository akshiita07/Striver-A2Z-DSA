class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> hashMap;
        int n = s.length();
        int i = 0;
        int ans = INT_MIN;
        for (int j = 0; j < n; j++) {
            hashMap[s[j]]++;
            while (hashMap[s[j]] > 2) {
                hashMap[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
