#include <bits/stdc++.h>
using namespace std;

bool isSpecial(const string &s)
{
    // all_of: checks if all elements in a range satisfy a given condition.
    //  lambda function defines the condition we want to check for each character in s.
    // It checks if every character c in the string s is equal to the first character s[0]
    return all_of(s.begin(), s.end(), [&](char c)
                  { return c == s[0]; });
}

int maximumLength(string s)
{
    // s: lowercase english letters
    // special string: made up of only a single character
    // Return length of longest special substring of s which occurs at least thrice
    int n = s.length();

    // Start checking from the longest possible substring length
    for (int i = n; i > 0; i--)
    {
        unordered_map<string, int> freq;

        // Generate all substrings of length len
        for (int j = 0; j <= n - i; j++)
        {
            string subString = s.substr(j, i);
            if (isSpecial(subString))
            {
                freq[subString]++;
                // If the substring occurs at least three times, return its length
                if (freq[subString] >= 3)
                {
                    return i;
                }
            }
        }
    }

    // If no special substring occurs at least thrice
    return -1;
}

int main()
{
    string s = "aaaa";
    cout << "\nLength of special string that occurs twice is: " << maximumLength(s);

    return 0;
}