class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        int n=s.length();
        // 1 indexed:
        for(int i=0;i<n;i++){
            int pos=abs(s[i]-'z')+1;
            ans+=pos*(i+1);
        }
        return ans;
    }
};
