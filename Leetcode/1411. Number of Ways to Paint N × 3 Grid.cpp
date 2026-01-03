class Solution {
public:
    const int MOD = 1e9 + 7;
    int numOfWays(int n) {
        // size of grid= n*3
        // three colors: Red, Yellow, or Green
        // no two adjacent cells have the same color

        // for n=1 ie for 1 row only:
        long long dpA = 6; // all 3 colors different
        long long dpB = 6; // 1st & 3rd same & middle different

        // for further rows:
        for (int i = 2; i <= n; i++) {
            long long newA = (dpA * 2 + dpB * 2) % MOD;
            long long newB = (dpA * 2 + dpB * 3) % MOD;
            dpA = newA;
            dpB = newB;
        }

        return (dpA + dpB) % MOD;
    }
};
