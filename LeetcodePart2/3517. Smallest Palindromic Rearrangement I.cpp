class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        if (n == 1) {
            return s;
        }
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        string firstHalf = "";
        string middle = "";

        for (int i = 0; i < 26; i++) {
            firstHalf += string(freq[i] / 2, char('a' + i));

            if (freq[i] % 2 == 1) {
                middle = char('a' + i);
            }
        }

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        return firstHalf + middle + secondHalf;
    }
};
