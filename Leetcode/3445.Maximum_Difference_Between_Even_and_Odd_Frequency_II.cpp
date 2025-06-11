#include <bits/stdc++.h>
using namespace std;

int maxDifference(string s, int k)
{
    // find maximum difference bw frequency of two characters, freq[a] - freq[b], in a substring subs of s st subs has a size of at least k & a:odd freq, b:even freq
    // Return the maximum difference.
    // string s contains only of digits '0' to '4'
    int n = s.length();
    int ans = INT_MIN;
    for (char a = '0'; a <= '4'; a++)
    {
        for (char b = '0'; b <= '4'; b++)
        {
            if (a == b)
            {
                continue;
            }
            vector<int> freq(5, 0);
            int left = 0;
            for (int right = 0; right < n; right++)
            {
                // freq increment:
                freq[s[right] - '0']++;
                while (right - left + 1 > k)
                {
                    freq[s[left] - '0']--;
                    left++;
                }
                if (right - left + 1 >= k)
                {
                    int aFreq = freq[a - '0'];
                    int bFreq = freq[b - '0'];
                    if (aFreq % 2 != 0 && bFreq % 2 == 0)
                    {
                        ans = max(ans, aFreq - bFreq);
                    }
                }
            }
        }
    }
    if (ans == INT_MIN)
    {
        return -1;
    }
    return ans;
}

int main()
{
    string s = "1122211";
    int k = 3;
    cout << "\nMaximum difference: " << maxDifference(s, k);

    return 0;
}