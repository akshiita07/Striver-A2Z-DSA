#include <bits/stdc++.h>
using namespace std;

int takeCharacters(string s, int k)
{
    // Each minute, you take either leftmost character or rightmost character of s
    //  Return  minimum number of minutes needed for you to take at least k of each character
    //  s consists of only the letters 'a', 'b', and 'c'
    int n = s.length();
    vector<int> hashArr(3, 0);
    for (int i = 0; i < n; i++)
    {
        // maintain count of each a,b,c:
        hashArr[s[i] - 'a']++;
    }
    if (n < k || hashArr[0] < k || hashArr[1] < k || hashArr[2] < k)
    {
        // not possible to take k times each letter:
        return -1;
    }

    // count how many reqd:
    int requiredA = hashArr[0] - k;
    int requiredB = hashArr[1] - k;
    int requiredC = hashArr[2] - k;
    int left = 0;
    int maxWindow = 0;
    vector<int> current(3, 0); // Current window count

    for (int right = 0; right < n; right++)
    {
        current[s[right] - 'a']++;

        // Shrink window if it exceeds the allowed remaining characters
        while (current[0] > requiredA || current[1] > requiredB || current[2] > requiredC)
        {
            current[s[left] - 'a']--;
            left++;
        }

        // Update maximum valid window size
        maxWindow = max(maxWindow, right - left + 1);
    }

    // Minimum minutes required
    return n - maxWindow;
}

int main()
{
    string s = "aabaaaacaabc";
    int k = 2;
    cout << "\nMin no of mins reqd are: " << takeCharacters(s, k);

    return 0;
}