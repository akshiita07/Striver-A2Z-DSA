class Solution {
public:
    bool isValid(int n) {
        // check entire number ie all digits:
        bool ans = false;
        while (n > 0) {
            int digit = n % 10;
            // check rotation:
            if (digit == 3 || digit == 4 || digit == 7) {
                // invalid:
                return false;
            }
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                ans = true;
            }
            // get next digit:
            n = n / 10;
        }
        return ans;
    }
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (isValid(i)) {
                count++;
            }
        }
        return count;
    }
};
