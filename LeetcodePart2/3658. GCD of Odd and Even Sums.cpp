class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n*n;
        int sumEven = n*(n+1);
        // find gcd of sumOdd & sumEven
        return gcd(sumOdd, sumEven);
    }
};
