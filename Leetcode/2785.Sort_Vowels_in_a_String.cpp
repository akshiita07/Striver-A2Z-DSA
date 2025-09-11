#include <bits/stdc++.h>
using namespace std;

string sortVowels(string s)
{
    // permute s to form a string t
    // all consonents must remain at the same place ie t[i]=s[i]
    // sort vowels in increasing order of their ASCII value
    vector<char> vowels;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            vowels.push_back(s[i]);
        }
    }
    // sort this vowels array by their
    sort(vowels.begin(), vowels.end());
    // loop thru string & replace vowels in order
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            s[i] = vowels[0];
            vowels.erase(vowels.begin());
        }
    }
    return s;
}

int main()
{
    string s = "lEetcOde";
    cout << "\nans= " << sortVowels(s);

    return 0;
}