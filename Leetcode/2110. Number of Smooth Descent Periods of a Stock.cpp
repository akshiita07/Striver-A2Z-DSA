class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        // prices[i] = stock price on the ith day
        // smooth descent period of a stock = one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1
        // price[today]-price[preceding-day]==1
        // 1st day of preiod: exempted
        // return no of smooth descent periods
        int n=prices.size();
        long long count=1;    //start from 1
        long long len=1;
        for(int i=1;i<n;i++){
            if(prices[i]==prices[i-1]-1){
                len++;
            }else{
                len=1;
            }
            count+=(long long)len;
        }
        return count;
    }
};
