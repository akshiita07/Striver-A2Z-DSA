#include <bits/stdc++.h>
using namespace std;

int maxFreqSum(string s)
{
    vector<int> hashMap(26, 0);
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        hashMap[s[i] - 'a']++;
    }
    // check vowels at indices a:0 e:4 i:8 o:14 u:20
    int maxVowel = INT_MIN;
    int maxConsonant = INT_MIN;
    for (int i = 0; i < 26; i++)
    {
        if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20)
        {
            // vowel indices:
            maxVowel = max(maxVowel, hashMap[i]);
        }
        else
        {
            // consonant indices:
            maxConsonant = max(maxConsonant, hashMap[i]);
        }
    }
    return maxVowel + maxConsonant;
}

int main()
{

    return 0;
}