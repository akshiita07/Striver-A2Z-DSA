#include <bits/stdc++.h>
using namespace std;
// each word must appear twice in s1 or s2 or in both s1+s2
// word that occur only once r uncommon

vector<string> uncommonFromSentences(string s1, string s2)
{
    vector<string> ans;

    // take hash table n maintain count of words
    unordered_map<string, int> hashMap;
    string word = "";       //take empty string
    for (int i = 0; i <= s1.length(); i++)  //need to check <= becuase last word does not has a space next so it also needs to be added
    {
        // until " " is obtained,it is 1 word
        if (s1[i] == ' ' || i==s1.length())
        {
            if (!word.empty())
            {
                hashMap[word]++;
                word = "";      //reset word after adding it in hashmap
            }
        }
        else
        {
            word += s1[i];
        }
    }
    for (int i = 0; i <= s2.length(); i++)  //need to check <= becuase last word does not has a space next so it also needs to be added
    {
        // until " " is obtained,it is 1 word
        if (s2[i] == ' ' || i==s2.length())
        {
            if (!word.empty())
            {
                hashMap[word]++;
                word = "";      //reset word after adding it in hashmap
            }
        }
        else
        {
            word += s2[i];
        }
    }

    for (auto it : hashMap)
    {
        if(it.second == 1)
        {
            ans.push_back(it.first);
        }
    }

    cout << "\nUncommon words are: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return ans;
}

int main()
{
    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";
    uncommonFromSentences(s1, s2);

    return 0;
}