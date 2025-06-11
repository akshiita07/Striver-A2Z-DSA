#include <bits/stdc++.h>
using namespace std;

int maxDifference(string s, int k)
{
    // find maximum difference bw frequency of two characters, freq[a] - freq[b], in a substring subs of s st subs has a size of at least k & a:odd freq, b:even freq
    // Return the maximum difference.
    // string s contains only of digits '0' to '4'
    auto getStatus = [](int cnt_a, int cnt_b) -> int
    {
        return ((cnt_a & 1) << 1) | (cnt_b & 1);
    };

    int n = s.size();
    int ans = INT_MIN;
    for (char a = '0'; a <= '4'; a++)
    {
        for (char b = '0'; b <= '4'; b++)
        {
            if (a == b)
            {
                continue;
            }
            int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
            int cnt_a = 0;
            int cnt_b = 0;
            int prev_a = 0;
            int prev_b = 0;
            int left = -1;
            for (int right = 0; right < n; right++)
            {
                cnt_a += (s[right] == a);
                cnt_b += (s[right] == b);
                while (right - left >= k && cnt_b - prev_b >= 2)
                {
                    int left_status = getStatus(prev_a, prev_b);
                    best[left_status] = min(best[left_status], prev_a - prev_b);
                    left++;
                    prev_a += (s[left] == a);
                    prev_b += (s[left] == b);
                }
                int right_status = getStatus(cnt_a, cnt_b);
                if (best[right_status ^ 0b10] != INT_MAX)
                {
                    ans = max(ans, cnt_a - cnt_b - best[right_status ^ 0b10]);
                }
            }
        }
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