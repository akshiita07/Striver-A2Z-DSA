class Solution {
public:
    int productDigits(int n) {
        int prod = 1;
        while (n > 0) {
            int remain = n % 10;
            prod *= remain;
            n = n / 10;
        }
        cout << "Product of digits of " << n << " is= " << prod;
        return prod;
    }
    int smallestNumber(int n, int t) {
        for (int i = n; i <= 100; i++) {
            int prod = productDigits(i);
            if (prod % t == 0) {
                return i;
            }
        }
        return 0;
    }
};
