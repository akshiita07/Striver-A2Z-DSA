#include <bits/stdc++.h>
using namespace std;

int canBeTypedWords(string text, string brokenLetters)
{
    int cnt = 0;
    // count the number of words that can be typed
    // word must not contain any broken letters
    unordered_set<char> brokenSet;
    for (auto it : brokenLetters)
    {
        brokenSet.insert(it);
    }
    stringstream ss(text);
    string word;
    // to read 1 word at a time:
    while (ss >> word)
    {
        bool canType = true;
        for (char ch : word)
        {
            if (brokenSet.find(ch) != brokenSet.end())
            {
                // found a broken letter so cannot be typed:
                canType = false;
                break;
            }
        }
        if (canType)
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    string text = ;
    string brokenLetters = ;

    return 0;
}