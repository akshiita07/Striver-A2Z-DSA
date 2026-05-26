class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        vector<int> hashMapSmall(26, 0);
        vector<int> hashMapUpper(26, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (word[i] >= 65 && word[i] <= 90) {
                hashMapUpper[word[i] - 'A']++;

            } else {
                hashMapSmall[word[i] - 'a']++;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (hashMapSmall[i] > 0 && hashMapUpper[i] > 0) {
                count++;
            }
        }
        return count;
    }
};
