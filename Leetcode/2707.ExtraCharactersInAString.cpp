#include <bits/stdc++.h>
using namespace std;

int extraChars(string &s, int index, set<string> dict)
{
    int n = s.size();
    // if entire string is processed then return 0:
    if (index == n)
    {
        return 0;
    }

    // int extra=INT_MAX;       //initilaise with a max value
    int extra = n;

    // try all substrings:
    for (int i = index; i < n; i++)
    {
        // find this substring
        string subString = s.substr(index, i - index + 1);
        // check if it exists in the dictionary or not:
        if (dict.find(subString) != dict.end())
        {
            // ie found this string in dictionary:
            // move:
            extra = min(extra, extraChars(s, i+ 1, dict));
        }
        else
        {
            // does not exists so add it in our dictionary:
            // added these extra characters: i-index+1
            extra = min(extra, i - index + 1 + extraChars(s, i+ 1, dict));
        }
    }
    return extra;
}

int minExtraChar(string s, vector<string> &dictionary)
{
    // break up string s into substrings that are prsent in dictionary
    // return those charcacters in s that r not present in dictionary
    // Return the minimum number of extra characters left over if you break up s string

    // 1. convert dictionary to an unordered set:
    set<string> dictUnorderedSet = set<string>(dictionary.begin(), dictionary.end());
    return extraChars(s, 0, dictUnorderedSet);
}

int main()
{
    string s = "sayhelloworld";
    vector<string> dictionary = {"hello", "world"};
    cout << "\nMin no of extra characters present in s but not in dict are: " << minExtraChar(s, dictionary);

    return 0;
}