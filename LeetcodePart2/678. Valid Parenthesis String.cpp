class Solution {
public:
    bool checkValidString(string s) {
        //low: min no of '('
        int low=0;
        //high: max no of ')'
        int high=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                low++;
                high++;
            }else if(s[i]==')'){
                low--;
                high--;
            }else{
                // '*'
                //if '(':
                low--;
                //if ')':
                high++;
            }
            if(high<0){
                return false;
            }
            low=max(0,low);
        }
        if(low==0){
            return true;
        }
        return false;
    }
};
