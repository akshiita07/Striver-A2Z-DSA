#include <bits/stdc++.h>
using namespace std;

int backtrack(string &s, int start, unordered_set<string> &used)
{
    if (start == s.size())
    {
        return 0; // If we reach the end of the string, no more splits can be made
    }

    int maxSplits = 0; // Store the maximum splits

    // Try splitting at different points
    string current = "";
    for (int i = start; i < s.size(); i++)
    {
        current += s[i];

        // If this substring is not already used, attempt a split
        if (used.find(current) == used.end())
        {
            used.insert(current); // Mark the substring as used

            // Recursively check the rest of the string and calculate splits
            int splits = 1 + backtrack(s, i + 1, used);

            maxSplits = max(maxSplits, splits); // Update the maximum splits

            used.erase(current); // Backtrack and remove the substring
        }
    }

    return maxSplits;
}

// Function to find the maximum number of unique substrings
int maxUniqueSplit(string s)
{
    unordered_set<string> used; // Set to keep track of used substrings
    return backtrack(s, 0, used);
}

int main()
{
    string s = "ababccc";
    cout << "\nMaxm no of unique splits are: " << maxUniqueSplit(s);

    return 0;
}