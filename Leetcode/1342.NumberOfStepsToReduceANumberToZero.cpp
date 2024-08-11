class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while (num != 0) {
            if (num % 2 == 0) {
                // even so divide by 2
                num = num / 2;
                count++;
            } else {
                // odd so subtract 1
                num = num - 1;
                count++;
            }
        }

        if (num == 0) {
            return count;
        }
        return count;
    }
};