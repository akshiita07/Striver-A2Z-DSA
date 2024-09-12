class Solution {
public:
    bool areOccurrencesEqual(string s) {
        // if all charcaters appear same times then good string:
        vector<int> hashMap(26, 0);
        for (int i = 0; i < s.length(); i++) {
            hashMap[s[i] - 'a']++;
        }
        int freq;
        for (auto it : hashMap) {
            if (it > 0) {
                freq = it;
            }
        }
        bool goodString=true;
        for (auto it : hashMap) {
            if (it > 0 && it != freq) {
                goodString=false;
            }
        }
        if(goodString){
            return true;
        }
        return false;
    }
};