#include <bits/stdc++.h>
using namespace std;

string toLower(const string &word)
{
    string res = word;
    transform(res.begin(), res.end(), res.begin(), ::tolower);
    return res;
}

// replace all vowels with a placeholder
string devowel(const string &word)
{
    string res = word;
    for (char &it : res)
    {
        if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u')
            it = '*';
    }
    return res;
}

vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
{
    // spell checker
    // convert query word to correct word
    // two categories of spelling mistakes
    // if query matches word in wordlist then return word with same case as in wordlist
    // if on replacing any vowels in query word-
    unordered_set<string> exactWords(wordlist.begin(), wordlist.end());
    unordered_map<string, string> caseInsensitiveMap;
    unordered_map<string, string> vowelErrorMap;

    for (const string &it : wordlist)
    {
        string lowerWord = toLower(it);
        string devoweledWord = devowel(lowerWord);

        // Store the first occurrence only for case-insensitive map
        if (caseInsensitiveMap.find(lowerWord) == caseInsensitiveMap.end())
        {
            caseInsensitiveMap[lowerWord] = it;
        }

        // Store the first occurrence only for vowel-error map
        if (vowelErrorMap.find(devoweledWord) == vowelErrorMap.end())
        {
            vowelErrorMap[devoweledWord] = it;
        }
    }

    vector<string> result;
    for (const string &it : queries)
    {
        if (exactWords.count(it))
        {
            // Exact match
            result.push_back(it);
        }
        else
        {
            string lowerQuery = toLower(it);
            string devoweledQuery = devowel(lowerQuery);

            if (caseInsensitiveMap.count(lowerQuery))
            {
                // Case-insensitive match
                result.push_back(caseInsensitiveMap[lowerQuery]);
            }
            else if (vowelErrorMap.count(devoweledQuery))
            {
                // Vowel error match
                result.push_back(vowelErrorMap[devoweledQuery]);
            }
            else
            {
                // No match
                result.push_back("");
            }
        }
    }
    return result;
}

int main()
{
    vector<string> wordlist = ;
    vector<string> queries = ;

    return 0;
}