#include <bits/stdc++.h>
using namespace std;

bool isPrefixAndSuffix(string str1, string str2)
{
    // returns true if str1 is both a prefix and a suffix of str2, and false otherwise
    int len1 = str1.length();
    int len2 = str2.length();
    if (len1 > len2)
    {
        return false;
    }
    if (str2.substr(0, len1) != str1)
    {
        return false;
    }
    if (str2.substr(len2 - len1) != str1)
    {
        return false;
    }
    return true;
}

int countPrefixSuffixPairs(vector<string> &words)
{
    // Return integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true
    int n = words.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isPrefixAndSuffix(words[i], words[j]) == true)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<string> words = {"a", "aba", "ababa", "aa"};
    cout << "\nNo of integer pairs are: " << countPrefixSuffixPairs(words);

    return 0;
}