class Solution {
public:
    const int MOD = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> pointNum;
        long long ans = 0;
        long long sum = 0;
        for (auto& it : points) {
            pointNum[it[1]]++;
        }
        for (auto& [_, pNum] : pointNum) {
            long long edge = (long long)pNum * (pNum - 1) / 2;
            ans += edge * sum;
            sum += edge;
        }
        return ans % MOD;
    }
};
