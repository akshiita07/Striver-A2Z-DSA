#include <bits/stdc++.h>
using namespace std;

int prefixCount(vector<string> &words, string pref)
{
    // Return the number of strings in words that contain pref as a prefix
    int count = 0;
    int len = pref.length();
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i].substr(0, len) == pref)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    vector<string> words = {"pay", "attention", "practice", "attend"};
    string pref = "at";
    cout << "\nThe no of strings with given prefix are: " << prefixCount(words, pref);

    return 0;
}