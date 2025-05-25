#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(vector<string> &words)
{
    // 2 lowercase english letters
    // Create the longest possible palindrome
    // Return the length of the longest palindrome that you can create else return 0
    unordered_map<string, int> hashMap;
    int lengthFinal = 0;
    for (auto it : words)
    {
        string reverseString = it;
        reverse(reverseString.begin(), reverseString.end());
        if (hashMap[reverseString] > 0)
        {
            // can form so word+reverse=2letter+2letter=4 letters
            lengthFinal += 4;
            hashMap[reverseString]--;
        }
        else
        {
            // store:
            hashMap[it]++;
        }
    }
    // for middle words like 'aa','cc':
    for (auto it : hashMap)
    {
        // double occuring words:
        if (it.first[0] == it.first[1] && it.second > 0)
        {
            lengthFinal += 2;
            break;
        }
    }
    return lengthFinal;
}

int main()
{
    vector<string> words = {"ab", "ty", "yt", "lc", "cl", "ab"};
    cout << "\nlength of the longest palindrome= " << longestPalindrome(words);

    return 0;
}