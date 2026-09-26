class Solution {
public:
    string findString(int i, string s) {
        string ans = "";
        int n = s.length();
        while (s[i] != ')') {
            ans += s[i];
            i++;
        }
        return ans;
    }

    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        unordered_map<string, string> hashMap;
        for (auto it : knowledge) {
            hashMap[it[0]] = it[1];
        }
        string res = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                // opening bracket:
                string ans = findString(i + 1, s);

                if (hashMap.find(ans) != hashMap.end()) {
                    res += hashMap[ans];
                } else {
                    res += '?';
                }
                while(s[i]!=')'){
                    i++;
                }
            }else{
                res+=s[i];
            }
        }
        return res;
    }
};
