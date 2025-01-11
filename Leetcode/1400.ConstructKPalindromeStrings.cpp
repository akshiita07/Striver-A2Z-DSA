#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string s, int k)
{
    //  return true: can use all the characters in s to construct k palindrome strings or false otherwise
    if (s.length() < k)
    {
        return false;
    }
    // hash table:
    unordered_map<char, int> hashMap;
    for (int i = 0; i < s.length(); i++)
    {
        hashMap[s[i]]++;
    }
    // count no of characters with ODD frequency:
    int oddCount = 0;
    for (auto it : hashMap)
    {
        // odd:
        if (it.second % 2 != 0)
        {
            oddCount++;
        }
    }

    // each palindrome must have only 1 odd character
    if (oddCount > k)
    {
        return false;
    }
    return true;
}

int main()
{
    string s1 = "annabelle";
    string s2 = "leetcode";
    int k1 = 2;
    int k2 = 3;
    cout << "\n1.Can we create k palindromic strings: " << canConstruct(s1, k1);
    cout << "\n2.Can we create k palindromic strings: " << canConstruct(s2, k2);

    return 0;
}