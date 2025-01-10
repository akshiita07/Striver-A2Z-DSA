#include <bits/stdc++.h>
using namespace std;

vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
{
    // Return an array of all the universal strings in words1
    vector<string> ans;
    vector<int> hashMap(26, 0);
    for (auto word : words2)
    {
        vector<int> freq(26, 0);
        for (auto ch : word)
        {
            freq[ch - 'a']++; // add in freq map
        }
        // calculate max frequency:
        for (int i = 0; i < 26; i++)
        {
            hashMap[i] = max(hashMap[i], freq[i]);
        }
    }
    for (auto word : words1)
    {
        // word must contain all letters of words2
        vector<int> freq(26, 0);
        for (auto ch : word)
        {
            freq[ch - 'a']++; // add in freq map
        }
        // check frequency:
        bool isUniversal = true;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] < hashMap[i])
            {
                // smaller freq than maximum
                isUniversal = false;
                break;
            }
        }
        if (isUniversal == true)
        {
            ans.push_back(word);
        }
    }
    return ans;
}

int main()
{
    vector<string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2 = {"e", "o"};
    vector<string> ans = wordSubsets(words1, words2);
    cout << "Ans\n";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}