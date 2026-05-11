class Solution {
public:
    vector<int> findDigits(int n){
        vector<int> digits;
        while(n>0){
            digits.push_back(n%10);
            n=n/10;
        }
        //to presernve order:
        reverse(digits.begin(),digits.end());
        return digits;
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=nums[i];
            if(num>9){
                //separate digits:
                vector<int> digits=findDigits(num);
                ans.insert(ans.end(),digits.begin(),digits.end());
            }else{
                //simply add:
                ans.push_back(num);
            }
        }
        return ans;
    }
};
