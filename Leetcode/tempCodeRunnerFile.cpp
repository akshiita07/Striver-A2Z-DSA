#include <bits/stdc++.h>
using namespace std;

long long countOfSubstrings(string word, int k)
{
    // lambda fnc:
    auto countSubstrings = [&](int k) -> long long
    {
        // Return total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once & exactly k consonants.
        int n = word.size();
        long long ans = 0;
        // create set of vowels:
        unordered_set<char> vowelsSet = {'a', 'e', 'i', 'o', 'u'};
        // create map for counting vowels:
        unordered_map<char, int> hashMap;
        long long consonants = 0;
        // take sliding windoe from l to r:
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            char currentChar = word[r];
            // add character in window if vowel:
            if (vowelsSet.find(currentChar) != vowelsSet.end())
            {
                hashMap[word[r]]++;
            }
            else
            {
                consonants++;
            }

            // chrink window if no of consonants > k:
            while (consonants > k)
            {
                char leftMostChar = word[l];
                if (vowelsSet.find(word[l]) != vowelsSet.end())
                {
                    hashMap[leftMostChar]--;
                    if (hashMap[leftMostChar] == 0)
                    {
                        hashMap.erase(leftMostChar);
                    }
                }
                else
                {
                    consonants--;
                }
                l++; // shrink window
            }
            // if all vowels & exactly k consonants are present in window:
            if (hashMap.size() == 5 && consonants == k)
            {
                ans += l;
            }
        }
    };
    return countSubstrings(k) - countSubstrings(k + 1);
}

int main()
{
    string word = "ieaouqqieaouqq";
    int k = 1;
    cout << "\n total number of substrings= " << countOfSubstrings(word, k);

    return 0;
}