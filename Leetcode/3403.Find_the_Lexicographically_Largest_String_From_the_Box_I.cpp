#include <bits/stdc++.h>
using namespace std;

string answerString(string word, int numFriends)
{
    // number of friends: numFriends
    // split "word" into numFriends parts st prev round did not have same split
    // Find the lexicographically largest string
    int n = word.size();
    if (numFriends == 1)
    {
        // ans is complete word as split into 1 friend
        return word;
    }
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, word.substr(i, min(n - i, n - numFriends + 1)));
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