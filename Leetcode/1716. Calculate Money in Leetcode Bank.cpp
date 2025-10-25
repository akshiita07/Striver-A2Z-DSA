class Solution {
public:
    int totalMoney(int n) {
        int startMonday = 0; // n=1
        int amount = 0;
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (i % 7 == 0) {
                // monday
                startMonday = startMonday + 1;
                amount = startMonday;
            }
            total += amount;
            amount += 1;
        }
        // now when n=1+7=8 then change n
        return total;
    }
};
