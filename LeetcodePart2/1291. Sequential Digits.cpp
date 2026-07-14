class BruteForce {
public:
    bool isSequential(int num) {
        // if each digit is sequential:
        string s = to_string(num);
        int len = s.length();
        for(int i=1;i<len;i++){
            if(s[i]!=s[i-1]+1){
                return false;
            }
        }
        return true;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = low; i <= high; i++) {
            if (isSequential(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        //form digits:
        for (int i = 1; i <= 9; i++) {
            int num=i;
            for(int j=i+1;j<=9;j++){
                num=num*10+j;
                if(num>=low && num<=high){
                    ans.push_back(num);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
