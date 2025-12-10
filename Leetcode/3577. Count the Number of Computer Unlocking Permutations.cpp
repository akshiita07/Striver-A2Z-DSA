class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        // n locked computers
        int n = complexity.size();
        // password of the computer i has a complexity complexity[i]
        if (*min_element(complexity.begin() + 1, complexity.end()) <=
            complexity[0]) {
            return 0;
        }

        int mod = 1000000007;
        int ans = 1;
        for (int i = 2; i < n; i++) {
            ans = static_cast<long long>(ans) * i % mod;
        }
        return ans;
    }
};
