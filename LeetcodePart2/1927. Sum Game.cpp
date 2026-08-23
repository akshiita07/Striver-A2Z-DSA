class Solution {
public:
    bool sumGame(string num) {
        // alice starts 1st
        // for each ? replace with digit 0 to 9
        // bob win: sum of digits in 1st half=2nd half else alice win
        int n = num.length();
        int half = n / 2;
        int L = 0;
        int R = 0;
        int diff = 0;
        // left half:
        for (int i = 0; i < half; i++) {
            if (num[i] == '?') {
                L++;
            } else {
                // left adds to difference
                diff += num[i] - '0';
            }
        }
        // right half:
        for (int i = half; i < n; i++) {
            if (num[i] == '?') {
                R++;
            } else {
                // rights subtracts to difference
                diff -= num[i] - '0';
            }
        }
        if (L == R) {
            // same no of ? on both sides
            if (diff == 0) {
                // bob wins
                return false;
            } else {
                // alice wins
                return true;
            }
        }
         // More '?' on the left
        if (L > R) {
            return 2 * diff != -9 * (L - R);
        }

        // More '?' on the right
        return 2 * diff != 9 * (R - L);
    }
};
