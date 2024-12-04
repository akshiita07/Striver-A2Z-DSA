#include <bits/stdc++.h>
using namespace std;

bool canMakeSubsequence(string str1, string str2)
{
    // select a set of indices in str1, and for each index i in the set, increment str1[i] to the next character cyclically ie 'a' becomes 'b', 'b' becomes 'c', and so on, and 'z' becomes 'a'

    // Return true if->possible to make str2 a subsequence of str1 by performing operation at most once else false .

    int n = str1.size();
    int m = str2.size();

    int j = 0; // Pointer for str2

    // Loop through str1 using pointer i
    for (int i = 0; i < n && j < m; i++)
    {
        // If characters match directly or if str1[i] can be incremented to match str2[j]
        if (str1[i] == str2[j] || (str1[i] + 1 - 'a') % 26 == (str2[j] - 'a') % 26)
        {
            j++; // Move to the next character in str2
        }
    }

    // If we've matched all characters of str2
    if (j == m)
    {
        // matched all characs
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string str1 = "abc";
    string str2 = "ad";
    cout << "\nCan make str1 a subsequence of str2: " << canMakeSubsequence(str1, str2);

    return 0;
}