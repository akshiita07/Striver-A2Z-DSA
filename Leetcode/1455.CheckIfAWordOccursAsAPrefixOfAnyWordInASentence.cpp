#include <bits/stdc++.h>
using namespace std;

int isPrefixOfWord(string sentence, string searchWord)
{
    // sentence (1-indexed)
    // check if searchWord is a prefix of any word in sentence & Return the index of the word in sentence

    // 1. extract words froms sentence into a vector
    vector<string> extractedWords;
    string curr = "";
    for (int i = 0; i <= sentence.length(); i++)
    {
        if (i == sentence.length() || sentence[i] == ' ')
        {
            if (!curr.empty())
            {
                extractedWords.push_back(curr);
                curr = "";
            }
        }
        else
        {
            curr += sentence[i];
        }
    }

    for (int i = 0; i < extractedWords.size(); i++)
    {
        if (extractedWords[i].find(searchWord) == 0)
        {
            return i + 1; // for 1 index
        }
    }
    return -1; // if not found
}

int main()
{
    string sentence = "i love eating burger";
    string searchWord = "burg";
    cout << "\nFound at: " << isPrefixOfWord(sentence, searchWord);

    return 0;
}