#include <bits/stdc++.h>
using namespace std;

bool containsVowel(string s)
{
    int n = s.length();
    bool vowelPresent = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            vowelPresent = true;
        }
    }
    return vowelPresent;
}
int countVowel(string s)
{
    int n = s.length();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            cnt++;
        }
    }
    return cnt;
}

bool doesAliceWin(string s)
{
    // alice starts first-> remove substring that consists of odd number of vowels
    // bob-> remove substring that consists of even number of vowels
    // first player who can't make a move-> looses
    // return true if alice wins game else false
    if (!containsVowel(s))
    {
        // if no vowel in initial string then alice looses
        return false;
    }
    int vowelCount = countVowel(s);
    if (vowelCount % 2 != 0)
    {
        // string contains odd number of vowels so alice wins
        return true;
    }
    // else if even no of vowels then alice removes odd no of vowels that makes no of remaining vowels odd so alice wins
    return true;
}

int main()
{
    string s = "";

    return 0;
}