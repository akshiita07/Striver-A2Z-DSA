class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        int count[corridor.length() + 1][3];

        count[corridor.length()][0] = 0;
        count[corridor.length()][1] = 0;
        count[corridor.length()][2] = 1;

        for (int index = corridor.length() - 1; index >= 0; index--) {
            if (corridor[index] == 'S') {
                count[index][0] = count[index + 1][1];
                count[index][1] = count[index + 1][2];
                count[index][2] = count[index + 1][1];
            } else {
                count[index][0] = count[index + 1][0];
                count[index][1] = count[index + 1][1];
                count[index][2] =
                    (count[index + 1][0] + count[index + 1][2]) % MOD;
            }
        }
        return count[0][0];
    }
};
