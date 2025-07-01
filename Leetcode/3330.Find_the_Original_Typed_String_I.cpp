#include <bits/stdc++.h>
using namespace std;

int possibleStringCount(string word)
{
    //  atmost 1 or 0 errors
    // Return total number of possible original strings that Alice might have intended to type
    int n = word.length();
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        // Count the number of consecutive characters
        int count = 1;
        while (i + 1 < n && word[i] == word[i + 1])
        {
            count++;
            i++;
        }
        if (count > 1)
        {
            while (count > 1)
            {
                ans++;
                count--;
            }
        }
    }
    return ans;
}

int main()
{
    string word = "abbcccca";
    cout << "\ntotal number of possible original strings= " << possibleStringCount(word);
    return 0;
}