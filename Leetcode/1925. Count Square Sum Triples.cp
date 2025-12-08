class Solution {
public:
    int countTriples(int n) {
        int noOfSqTriples = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int c=int(sqrt(a * a + b * b));
                if (c<=n && c*c==a * a + b * b){
                    noOfSqTriples++;
                }
            }
        }
        return noOfSqTriples;
    }
};
