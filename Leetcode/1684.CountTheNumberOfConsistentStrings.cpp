#include <bits/stdc++.h>
using namespace std;

int countConsistentStrings(string allowed, vector<string> &words)
{
    // A string is consistent if all characters in the string appear in the string allowed
    // Return the number of consistent strings in the array words

    // loop thru all words & check if there exists any different charcter than in allowed:
    vector<int> hashMap(26, 0);
    for (int i = 0; i < allowed.length(); i++)
    {
        // store it in hashMap with int index
        hashMap[allowed[i] - 'a']++;
    }
    // start from 0:
    int count = 0;
    // loop thru words array
    for (int i = 0; i < words.size(); i++)
    {
        // bool to check if consistennt for each word
        bool isCons = true;
        string specificWord = words[i];
        // loop thru word content
        for (int j = 0; j < specificWord.length(); j++)
        {
            if (hashMap[specificWord[j] - 'a'] == 0)
            {
                isCons = false;
                break;
            }
        }
        // if consistent word then only inc count
        if (isCons)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string allowed = "ab";
    vector<string> words = {"ad", "bd", "aaab", "baa", "badab"};
    cout << "\nThe no of consistent words are: " << countConsistentStrings(allowed, words);
    // Output: 2

    return 0;
}