#include <bits/stdc++.h>
using namespace std;

string answerString(string word, int numFriends)
{
    // number of friends: numFriends
    // split "word" into numFriends parts st prev round did not have same split
    // Find the lexicographically largest string
    int n = word.size();
    int minLen = n - numFriends + 1;
    string ans = "";
    for (int i = 0; i <= n - minLen; i++)
    {
        // try all substrings of this length
        string curr = word.substr(i, minLen);
        if (curr > ans)
        {
            // take lexicographically largest string:
            ans = curr;
        }
    }
    return ans;
}

int main()
{
    string word = "dbca";
    int numFriends = 2;
    cout << "\nlexicographically largest string= " << answerString(word, numFriends);

    return 0;
}