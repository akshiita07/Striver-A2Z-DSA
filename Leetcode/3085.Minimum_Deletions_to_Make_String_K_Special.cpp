#include <bits/stdc++.h>
using namespace std;

int minimumDeletions(string word, int k)
{
    // word is k special if |freq(word[i]) - freq(word[j])| <= k
    // Return the minimum number of characters you need to delete to make word k-special
    // create map for freq of each character
    unordered_map<char, int> freqMap;
    for (auto it : word)
    {
        freqMap[it]++;
    }
    // smallest freq character will never be deleted:
    char c = word[0];
    int x = freqMap[word[0]];
    int n = word.length();
    // cout << "\nChar with min freq " << c << " : " << x;
    // Let next character be d with freq y
    // if y<x then delete all occ of char d
    // if y>x+k then delete y-x-k occ of char d
    // push all freq into a vector:
    vector<int> freqVec;
    for (auto it : freqMap)
    {
        freqVec.push_back(it.second);
    }
    int ans = INT_MAX;
    // try from 1 to max freq & select it as min freq character:
    for (int i = 1; i <= *max_element(freqVec.begin(), freqVec.end()); i++)
    {
        int count = 0;
        for (auto it : freqVec)
        {
            if (it < i)
            {
                count += it;
            }
            else if (it > i + k)
            {
                count += it - i - k;
            }
        }
        ans = min(ans, count);
    }
    return ans;
}

int main()
{
    string word = "aabcaba";
    int k = 0;
    cout << "\nMinimum Deletions to Make String K-Special: " << minimumDeletions(word, k);

    return 0;
}