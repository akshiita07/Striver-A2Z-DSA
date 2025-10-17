#include <bits/stdc++.h>
using namespace std;

// brute force
int countNumberOfPartitions(string &s, int k)
{
    int n = s.length();
    int partitions = 0;
    int l = 0;
    unordered_map<char, int> hashMap;
    for (int r = 0; r < n; r++)
    {
        hashMap[s[r]]++;
        while (hashMap.size() > k)
        {
            hashMap.clear();
            partitions++;
            hashMap[s[r]]++;
        }
    }
    return partitions + 1;
}

int maxPartitionsAfterOperations(string s, int k)
{
    // change at most one index in s to another lowercase English letter
    // until s is empty: Choose the longest prefix of s containing at most k distinct characters then Delete the prefix from s and increase the number of partitions by one
    int n = s.length();
    int ans = countNumberOfPartitions(s, k);
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        for (char j = 'a'; j <= 'z'; j++)
        {
            if (c == j)
            {
                continue;
            }
            s[i] = j;
            ans = max(ans, countNumberOfPartitions(s, k));
        }
        s[i] = c;
    }
    return ans;
}

// optimal: couldnt think:
class Solution
{
public:
    int maxPartitionsAfterOperations(string s, int k)
    {
        int n = s.length();
        vector<vector<int>> left(n, vector<int>(3)), right(n, vector<int>(3));
        int num = 0, mask = 0, count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int binary = 1 << (s[i] - 'a');
            if (!(mask & binary))
            {
                count++;
                if (count <= k)
                {
                    mask |= binary;
                }
                else
                {
                    num++;
                    mask = binary;
                    count = 1;
                }
            }
            left[i + 1][0] = num;
            left[i + 1][1] = mask;
            left[i + 1][2] = count;
        }

        num = 0, mask = 0, count = 0;
        for (int i = n - 1; i > 0; i--)
        {
            int binary = 1 << (s[i] - 'a');
            if (!(mask & binary))
            {
                count++;
                if (count <= k)
                {
                    mask |= binary;
                }
                else
                {
                    num++;
                    mask = binary;
                    count = 1;
                }
            }
            right[i - 1][0] = num;
            right[i - 1][1] = mask;
            right[i - 1][2] = count;
        }

        int Max = 0;
        for (int i = 0; i < n; i++)
        {
            int seg = left[i][0] + right[i][0] + 2;
            int totMask = left[i][1] | right[i][1];
            int totCount = 0;
            while (totMask)
            {
                totMask = totMask & (totMask - 1);
                totCount++;
            }
            if (left[i][2] == k && right[i][2] == k && totCount < 26)
            {
                seg++;
            }
            else if (min(totCount + 1, 26) <= k)
            {
                seg--;
            }
            Max = max(Max, seg);
        }
        return Max;
    }
};

int main()
{

    return 0;
}