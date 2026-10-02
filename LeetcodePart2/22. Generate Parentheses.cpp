class Solution {
public:
    void solve(int n, int open, int close, string curr, vector<string>& ans){
        //open: no of valid ( 
        //close: no of valid ) 
        if(open==n && close==n){
            // all brackets used:
            ans.push_back(curr);
            return;
        }
        if(open<n){
            //add more (
            solve(n,open+1,close,curr+'(', ans);
        }
        if(close<open){
            //add more )
            solve(n,open,close+1,curr+')', ans);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,0,0,"",ans);
        return ans;
    }
};
