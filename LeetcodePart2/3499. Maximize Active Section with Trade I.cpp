class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int ones = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ones++;
            }
        }
        string t = "1" + s + "1";
        // create digit & its count as groups
        vector<pair<char, int>> groupDigits;
        for (char c : t) {
            if (groupDigits.empty() || groupDigits.back().first != c) {
                groupDigits.push_back({c, 1});
            } else {
                groupDigits.back().second++;
            }
        }

        int ans = ones;
        for (int i = 1; i < groupDigits.size()-1; i++) {
            if (groupDigits[i].first == '1' && groupDigits[i - 1].first == '0' &&
                groupDigits[i + 1].first == '0') {

                int gain = groupDigits[i - 1].second + groupDigits[i + 1].second;
                ans = max(ans, ones + gain);
            }
        }
        return ans;
    }
};
