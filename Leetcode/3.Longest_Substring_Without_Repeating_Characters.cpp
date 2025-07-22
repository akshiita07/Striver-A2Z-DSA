#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    // find the length of the longest substring without duplicate characters
    unordered_set<char> duplicate;
    int n = s.length();
    int left = 0;
    int right = 0;
    int maxLength = INT_MIN;
    int currLen = 0;
    while (right < n)
    {
        // check if already present:
        while (duplicate.find(s[right]) != duplicate.end())
        {
            // remove & shorten window
            duplicate.erase(s[left]);
            currLen--;
            left++;
        }
        // add rightmost element:
        duplicate.insert(s[right]);
        currLen++;
        maxLength = max(maxLength, currLen);
        right++;
    }
    return maxLength;
}

int main()
{
    string s = "pwwkew";
    cout << "\nLength of the longest substring without repeating characters= " << lengthOfLongestSubstring(s);

    return 0;
}