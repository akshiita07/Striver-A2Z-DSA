#include <bits/stdc++.h>
using namespace std;

bool areAlmostEqual(string s1, string s2)
{
    int n = s1.length(); // both have same length
    if (s1 == s2)
    {
        return true;
    }
    // check if difference in positions= either 0 or 2 only:
    int i = 0;
    int j = 0;
    vector<int> mismatchIndex;
    while (i < n)
    {
        if (s1[i] != s2[j])
        {
            mismatchIndex.push_back(i); // add index
        }
        i++;
        j++;
    }
    int count = mismatchIndex.size(); // no of mismatched indices
    if (count != 2)
    {
        return false; // not possible for more than 2 indices mismatched
    }
    // now check if same characters:
    int firstChar = mismatchIndex[0];
    int secondChar = mismatchIndex[1];
    swap(s1[firstChar], s1[secondChar]);
    if (s1 == s2)
    {
        return true;
    }
    return false; // even after swap not possible
}

int main()
{
    string s1 = "bank";
    string s2 = "kanb";
    cout << "\npossible to make both strings equal= " << areAlmostEqual(s1, s2);

    return 0;
}