#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();
    // if 2nd word does not contain enough digits as in n1 then exit
    if (s2.length() < s1.length())
    {
        return false;
    }

    // 2 hash maps to mainatin count of letters
    vector<int> count1(26, 0);
    vector<int> count2(26, 0);

    // add digits of string in hash map 1 and 2
    for (int i = 0; i < n1; i++)
    {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }

    for (int i = n1; i < n2; ++i)
    {
        if (count1 == count2)
            return true;
        ++count2[s2[i] - 'a'];
        --count2[s2[i - n1] - 'a'];
    }

    return count1 == count2;
}

int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << "\nDoes s2 contain permutation of s1: " << checkInclusion(s1, s2);

    return 0;
}