#include <bits/stdc++.h>
using namespace std;

vector<string> stringMatching(vector<string> &words)
{
    //  return all strings in words that is a substring of another word
    int n = words.size();
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // check if word[i] is a subtring of word[j]
            // npos checks if a substring exists or not in a string
            if (i != j && words[j].find(words[i]) != string::npos)
            {
                ans.push_back(words[i]);
                break;
            }
        }
    }
    return ans;
}

int main()
{
    vector<string> words = {"mass", "as", "hero", "superhero"};
    vector<string> ans = stringMatching(words);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}