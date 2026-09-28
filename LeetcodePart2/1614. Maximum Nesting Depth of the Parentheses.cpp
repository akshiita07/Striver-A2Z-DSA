class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        int ans=0;
        int depth=0;
        // find max nested depth of ()
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                //opening bracket
                depth++;
                ans=max(ans,depth);
            }else if(s[i]==')'){
                //closing
                depth--;
            }
        }
        return ans;
    }
};
