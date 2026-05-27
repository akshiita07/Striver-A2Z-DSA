class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        vector<int> hashMapSmall(26, 0);
        vector<int> hashMapUpper(26, 0);
        vector<int> occurrenceSmall(26, -1);
        vector<int> occurrenceUpper(26, -1);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (word[i] >= 65 && word[i] <= 90) {
                hashMapUpper[word[i] - 'A']++;
                if (occurrenceUpper[word[i] - 'A'] == -1) {
                    // first occ of uppercase
                    occurrenceUpper[word[i] - 'A'] = i;
                }

            } else {
                hashMapSmall[word[i] - 'a']++;
                //last occ of lowercase
                occurrenceSmall[word[i] - 'a'] = i;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (hashMapSmall[i] > 0 && hashMapUpper[i] > 0 &&
                (occurrenceSmall[i] < occurrenceUpper[i])) {
                count++;
            }
        }
        return count;
    }
};
