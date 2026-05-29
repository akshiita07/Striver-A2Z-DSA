class Solution {
public:
    int sumOfDigits(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        vector<int> newArr;
        for(int i=0;i<nums.size();i++){
            int newNum=sumOfDigits(nums[i]);
            newArr.push_back(newNum);
        }
        return *min_element(newArr.begin(),newArr.end());
    }
};
