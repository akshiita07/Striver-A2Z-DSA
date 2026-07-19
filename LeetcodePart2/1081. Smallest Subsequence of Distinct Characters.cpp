class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26,0);
        vector<bool> visited(26,false);
        for(auto it:s){
            freq[it-'a']++;
        }
        string ans;
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']--;
            if(visited[s[i]-'a']){
                continue;
            }
            while(!ans.empty() && ans.back()>s[i] && freq[ans.back()-'a']>0){
                visited[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            visited[s[i]-'a']=true;
        }
        return ans;
    }
};
