class Solution {
public:
    int digitSum(int n){
        int sum=0;
        while(n>0){
            int remain=n%10;
            sum+=remain;
            n=n/10;
        }
        return sum;
    }
    int digitProduct(int n){
        int prod=1;
        while(n>0){
            int remain=n%10;
            prod*=remain;
            n=n/10;
        }
        return prod;
    }
    bool checkDivisibility(int n) {
        int dSum=digitSum(n);
        int dProd=digitProduct(n);
        if(n%(dSum+dProd)==00){
            // divisible by both
            return true;
        }
        return false;
    }
};
