class Solution {
public:
    string processStr(string s) {
        string result="";
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                //remove last char from res
                if(result.length()>0){
                    result.pop_back();
                }
                cout<<"At step * result is: "<<result<<endl;
            }else if(s[i]=='#'){
                //deuplicate res & add to itself
                result+=result;
                cout<<"At step # result is: "<<result<<endl;
            }else if(s[i]=='%'){
                //reverse res
                reverse(result.begin(),result.end());
                cout<<"At step % result is: "<<result<<endl;
            }else{
                //normal lowercase: append to res
                result+=s[i];
                cout<<"At step ch result is: "<<result<<endl;
            }
        }
        return result;
    }
};
