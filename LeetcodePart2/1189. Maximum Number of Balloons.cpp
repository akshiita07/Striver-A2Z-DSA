class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> hashMap;
        int n=text.length();
        for(int i=0;i<n;i++){
            if(text[i]=='b' || text[i]=='a' || text[i]=='n' || text[i]=='l' || text[i]=='o'){
                hashMap[text[i]]++;
            }
        }
        return min({hashMap['b'],hashMap['a'],hashMap['l']/2,hashMap['o']/2,hashMap['n']});
    }
};
