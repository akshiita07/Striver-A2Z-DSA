#include <bits/stdc++.h>
using namespace std;

bool checkEvenCount(vector<int> &vowels)
{
    for (int i = 0; i < vowels.size(); i++)
    {
        // check if it appears evn no of times
        if (vowels[i] % 2 != 0)
        {
            return false;
        }
    }
    return true;
}

int findTheLongestSubstring(string s)
{
    //  return the size of the longest substring containing each vowel an even number of times ie 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

    vector<int> vowels(5, 0);
    int len = 0;
    // map vowels to an index in vowels:
    unordered_map<char, int> hashMap = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};

    // use 2 ptrs to traverse this string
    for (int i = 0; i < s.length(); i++)
    {
        vector<int> currentVow(5, 0);
        for (int j = i; j < s.length(); j++)
        {
            // if it is a vowel then inc its count:
            if (hashMap.find(s[j]) != hashMap.end())
            {
                currentVow[hashMap[s[j]]]++;
            }
            // check if all vowels have even count then update the max length of substring
            if (checkEvenCount(currentVow) == true)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}

int main()
{
    string s = "eleetminicoworoep";
    cout << "\nLength of longest substring containing vowels equal no of times is: " << findTheLongestSubstring(s);

    return 0;
}