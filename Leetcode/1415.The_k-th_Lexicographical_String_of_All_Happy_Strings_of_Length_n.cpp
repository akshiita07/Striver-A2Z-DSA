#include <bits/stdc++.h>
using namespace std;

// function to generate happy strings recursively:
void generateHappyStrings(int n, string current, vector<string> &happyStrings)
{
    // if we reach the size n then push it into vector:
    if (current.size() == n)
    {
        happyStrings.push_back(current);
        return;
    }
    // create string current only using 'a','b','c'
    for (char ch : {'a', 'b', 'c'})
    {
        // if it is starting letter OR if last character & this character are NOT same
        if (current.empty() || current.back() != ch)
        {
            generateHappyStrings(n, current + ch, happyStrings);
        }
    }
}

string getHappyString(int n, int k)
{
    // happy string consists of letters from ['a', 'b', 'c'] set
    // s[i] != s[i + 1]
    // create a list of happy strings of length n sorted in lexicographical order
    // return k-th string of this list else empty string
    vector<string> happyStrings;
    generateHappyStrings(n, "", happyStrings);
    if (k > happyStrings.size())
    {
        // return empty sring when size exceeds
        return "";
    }
    return happyStrings[k - 1]; // as 1 based indexing
}

int main()
{
    int n = 3;
    int k = 9;
    cout << "\nHappy string is:" << getHappyString(n, k);

    return 0;
}