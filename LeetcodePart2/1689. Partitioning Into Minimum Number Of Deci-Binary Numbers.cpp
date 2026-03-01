class Solution {
public:
    int minPartitions(string n) {
        // for number 9-> 9 digits reqd so take max of each digit 
        int maxDigits=0;
        for(auto it:n){
            // each character c:
            maxDigits=max(maxDigits,it-'0');
        }
        return maxDigits;
    }
};
