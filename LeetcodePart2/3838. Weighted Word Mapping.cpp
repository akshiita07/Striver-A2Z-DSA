class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        vector<int> wordWeights(n,0);
        for (int i = 0; i < n; i++) {
            // for each word:
            string word = words[i];
            int m = word.length();
            int sum = 0;
            for (int j = 0; j < m; j++) {
                // for all characters in word
                sum += weights[word[j] - 'a'];
            }
            wordWeights[i] = sum;
        }
        string ans="";
        for(int i=0;i<n;i++){
            int weight=wordWeights[i];
            weight=weight%26;
            char c='z'-weight;
            ans+=c;
        }
        return ans;
    }
};
