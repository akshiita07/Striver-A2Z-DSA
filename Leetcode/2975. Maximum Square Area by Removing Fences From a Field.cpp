class Solution {
public:
    const int mod = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {
        // boundaries:
        hFences.push_back(1);
        hFences.push_back(m);
        // vertical:
        vFences.push_back(1);
        vFences.push_back(n);

        // sort
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<long long> hDiffs;

        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hDiffs.insert(hFences[j] - hFences[i]);
            }
        }

        long long ans = -1;

        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                long long d = vFences[j] - vFences[i];
                if (hDiffs.count(d)) {
                    ans = max(ans, d);
                }
            }
        }

        if (ans == -1) {
            return -1;
        }
        return (ans * ans) % mod;
    }
};
