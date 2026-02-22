class Solution {
public:
    string findBinary(int n) {
        string ans = "";
        int i = n;
        int rem;
        while (i > 0) {
            rem = i % 2;
            i = i / 2;
            ans += char('0' + rem);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> findSetBits(string s){
        int n=s.length();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ans[i]=1;
            }
        }
        return ans;
    }

    int binaryGap(int n) {
        // bin representation of n:
        string binaryRep=findBinary(n);
        //  longest distance between adjacent 1s
        vector<int> setBits=findSetBits(binaryRep);
        int len=setBits.size();
        int ans=0;
        int prev=-1;
        for(int i=0;i<len;i++){
            if(setBits[i]==1){
                if(prev!=-1){
                    // found earlier 1 already
                    ans=max(ans,i-prev);
                }
                prev=i; //this is 1 found

            }
        }
        return ans;
    }
};
