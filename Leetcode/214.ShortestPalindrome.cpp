#include <bits/stdc++.h>
using namespace std;
// check if a given string is palindrome or not
bool isPalindrome(string &s, int len)
{
    int i = 0;
    int j = len; // got till this length
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++; // increment
        j--; // decrement
    }
    return true;
}

string shortestPalindrome(string s)
{
    // convert s to a palindrome by adding characters in front of it
    int n = s.length();
    // start checking from last is is abcd a palindrome? then is abc? then ab? then a?
    int remain = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        // start from s & go till i
        if (isPalindrome(s, i) == true)
        {
            // now we got a palindrome so remaining chars after it have to be reversed & appended
            remain = i + 1;
            break;
        }
    }
    string suffixToAdd = s.substr(remain);
    reverse(suffixToAdd.begin(), suffixToAdd.end());
    return suffixToAdd + s;
}

int main()
{
    string s = "aacecaaa";
    cout << "\nShortest palindrome is: " << shortestPalindrome(s);

    return 0;
}