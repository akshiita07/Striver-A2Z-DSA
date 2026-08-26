class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        for (int i = 0; i < n; i++) {
            int ones = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '1') {
                    ones++;
                }
                if (ones == k) {
                    string curr=s.substr(i,j-i+1);
                    if (ans == "") {
                        //append ans:
                        ans=curr;
                    }else if(curr.length()<ans.length()){
                        //smaller length
                        ans=curr;
                    }else if(curr.length()==ans.length() && curr<ans){
                        //same length then lexicog smaller
                        ans=curr;
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
