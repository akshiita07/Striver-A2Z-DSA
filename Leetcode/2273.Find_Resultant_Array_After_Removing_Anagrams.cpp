#include <bits/stdc++.h>
using namespace std;

vector<string> removeAnagrams(vector<string> &words)
{
    // select index i such that words[i] and words[i-1] are anagrams then delete words[i]
    // return remaining words
    int n = words.size();
    vector<string> ans;
    string prev = "";
    for (auto it : words)
    {
        string sortedWord = it;
        sort(sortedWord.begin(), sortedWord.end());
        if (sortedWord != prev)
        {
            ans.push_back(it);
            prev = sortedWord;
        }
    }
    return ans;
}

int main()
{
    vector<string> words = {};

    return 0;
}