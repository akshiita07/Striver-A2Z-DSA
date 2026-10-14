class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // no of digits in n == num
        // sum of digits of n == sum
        // score of n = sum of squares of digits of n
        // maxm sxore

        // if digits cant add upto sum then:
        if(sum>9*num){
            return "";
        }
        string ans="";
        // add leftmost 9s
        while(sum>=9){
            ans+='9';
            sum-=9;
        }
        //remaining digits:
        if(sum>0){
            ans+=char('0'+sum);
        }
        // fill remaining digits with 0:
        while(ans.length()<num){
            ans+='0';
        }
        return ans;
    }
};
