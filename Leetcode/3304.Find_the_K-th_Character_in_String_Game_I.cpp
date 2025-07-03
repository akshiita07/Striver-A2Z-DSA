#include <bits/stdc++.h>
using namespace std;

char kthCharacter(int k)
{
    // Alice string: word = "a"
    // operation: append the next character in english alphabet to the end of word
    // perform operation such that word length >=k
    // return this kth character of word
    string word = "a";
    while (word.length() < k)
    {
        // for each character do it:
        int n = word.length();
        for (int i = 0; i < n; i++)
        {
            char nextChar = 'a' + (word[i] - 'a' + 1) % 26;
            word += nextChar;
        }
        cout << "\nWord is: " << word;
    }
    return word[k - 1];
}

int main()
{
    int k = 5;
    cout << "\nvalue of the kth character in word= " << kthCharacter(k);

    return 0;
}