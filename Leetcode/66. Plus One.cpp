class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {

            int sum = digits[i] + carry;
            if (sum > 9) {
                carry = 1;
                sum = sum % 10;
            }else{
                carry=0;
            }
            ans.push_back(sum);
        }
        if(carry==1){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        cout << "\nAfter plus one the anser is: \n";
        for (auto it : ans) {
            cout << it << " ";
        }
        return ans;
    }
};
