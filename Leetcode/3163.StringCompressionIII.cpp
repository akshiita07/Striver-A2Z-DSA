#include <bits/stdc++.h>
using namespace std;

string compressedString(string word)
{
    // empty string
    string comp = "";
    int cnt = 0;

    while (cnt < word.length())
    {
        // Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
        // Append the length of the prefix followed by c to comp.
        char currentChar = word[cnt];
        int noOfTimesRepeat = 0;
        while (cnt < word.length() && word[cnt] == currentChar && noOfTimesRepeat < 9)
        {
            // repeating word
            noOfTimesRepeat++;
            cnt++;
        }

        comp += to_string(noOfTimesRepeat) + currentChar;
    }
    return comp;
}

int main()
{
    string word = "abcde";
    cout << "\nComp string is: " << compressedString(word);

    return 0;
}