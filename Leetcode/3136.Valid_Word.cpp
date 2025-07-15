#include <bits/stdc++.h>
using namespace std;

bool isValid(string word)
{
    // 1. min 3 characs ie length>=3
    // 2. only 0-9 digits & a-z & A-Z allowed
    // 3. atleast 1 vowel (a,e,i,o,u) & consonant must be present
    int n = word.length();
    if (n < 3)
    {
        return false;
    }
    bool hasVowel = false;
    bool hasConsonant = false;
    for (int i = 0; i < n; i++)
    {
        char ch = word[i];
        if (isdigit(ch) || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            // check for vowel:
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            {
                hasVowel = true;
            }
            else
            {
                if (!isdigit(ch))
                {
                    hasConsonant = true;
                }
            }
        }
        else
        {
            // invalid character:
            return false;
        }
    }
    if (hasVowel == true && hasConsonant == true)
    {
        // all conditions satisfied
        return true;
    }
    return false;
}

int main()
{
    string word1 = "a3$e";
    string word2 = "234Adas";
    cout << "\nword1 is valid?: " << isValid(word1);
    cout << "\nword2 is valid?: " << isValid(word2);
    return 0;
}