class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.length();
        stack<int> st;
        st.push(0); //current score
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(0);
            }else{
                int inside=st.top();
                st.pop();
                int curr=0;
                if(inside==0){
                    //ie ()
                    curr=1;
                }else{
                    //ie (A)
                    curr=2*inside;
                }
                //AB
                st.top()+=curr;
            }
        }
        return st.top();
    }
};
