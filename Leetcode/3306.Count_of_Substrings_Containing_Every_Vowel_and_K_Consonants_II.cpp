#include <bits/stdc++.h>
using namespace std;

long long brute_force(string word, int k)
{
    // Return total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once & exactly k consonants.
    int n = word.size();
    long long ans = 0;
    // create set of vowels:
    unordered_set<char> vowelsSet = {'a', 'e', 'i', 'o', 'u'};
    // take sliding windoe from l to r:
    for (int l = 0; l < n; l++)
    {
        // create map for counting vowels:
        unordered_map<char, int> hashMap;
        long long consonants = 0;
        for (int r = l; r < n; r++)
        {
            char currentChar = word[r];
            // add character in window if vowel:
            if (vowelsSet.find(currentChar) != vowelsSet.end())
            {
                hashMap[currentChar]++;
            }
            else
            {
                consonants++;
            }
            if (consonants > k)
            {
                break;
            }
            // shrink window if no of consonants > k:
            if (hashMap.size() == 5 && consonants == k)
            {
                ans++;
            }
        }
    }
    return ans;
}

long long countOfSubstrings(string word, int k)
{
    auto countSubstrings = [&](int k) -> long long
    {
        long long ans = 0;
        int l = 0;
        long long consonants = 0;
        unordered_map<char, int> hashMap;
        auto vowel = [&](char c) -> bool
        {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        for (char c : word)
        {
            if (vowel(c))
            {
                hashMap[c]++;
            }
            else
            {
                ++consonants;
            }
            while (consonants >= k && hashMap.size() == 5)
            {
                char leftMostChar = word[l++];
                if (vowel(leftMostChar))
                {
                    if (--hashMap[leftMostChar] == 0)
                    {
                        hashMap.erase(leftMostChar);
                    }
                }
                else
                {
                    --consonants;
                }
            }
            ans += l;
        }
        return ans;
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