#include <bits/stdc++.h>
using namespace std;

bool isCircularSentence(string sentence)
{
    // A sentence is circular if:
    // last character of a word is equal to the first character of the next word.
    // last character of the last word is equal to the first character of the first word.

    // split sentence into array of words:
    vector<string> words;
    int n = sentence.length();
    string currentWord;

    for (int i = 0; i < n; i++)
    {
        // next word started:
        if (sentence[i] == ' ')
        {
            if (!currentWord.empty())
            {
                words.push_back(currentWord);
                currentWord.clear();
            }
        }
        else
        {
            currentWord += sentence[i];
        }
    }
    // add last word also(ends without space)
    if (!currentWord.empty())
    {
        words.push_back(currentWord);
    }

    int m = words.size();
    for (int i = 0; i < m - 1; i++)
    {
        // word & next word
        if (words[i].back() == words[i + 1].front())
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    // now check last word & 1st word
    if (words[0].front() != words[m - 1].back())
    {
        return false;
    }
    return true;
}

int main()
{
    string sentence = "leetcode exercises sound delightful";
    cout << "\nIs the sentence circular: " << isCircularSentence(sentence);

    return 0;
}