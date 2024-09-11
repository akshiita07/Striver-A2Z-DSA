class Solution {
public:
    int firstUniqChar(string s) {
        // give element that appears only once
        unordered_map<char,int> mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }
        for(int i=0;i<s.length();i++){
            if(mpp[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};