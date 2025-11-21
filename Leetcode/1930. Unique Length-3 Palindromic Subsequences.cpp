class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // return no of unique palindromes(reads the same forwards and backwards) of length 3 that are subsequences of s
    int n = s.length();
    unordered_set<string> uniquePalindromes; // push palindromes into this set to avoid duplicates

    // use 2 arrays to track elements
    vector<int> left(26, 0);
    vector<int> right(26, 0);

    // Build the `right` array
    for (int i = 0; i < n; i++)
    {
        right[s[i] - 'a']++;
    }

    // Build the `left` array and calculate palindromes
    for (int i = 0; i < n; i++)
    {
        right[s[i] - 'a']--;

        // Check palindromes of the form xAx
        for (int ch = 0; ch < 26; ch++)
        {
            if (left[ch] > 0 && right[ch] > 0)
            {
                string palindrome = string(1, ch + 'a') + s[i] + string(1, ch + 'a');
                uniquePalindromes.insert(palindrome);
            }
        }
        left[s[i] - 'a']++;
    }

    return uniquePalindromes.size();
    }
};
