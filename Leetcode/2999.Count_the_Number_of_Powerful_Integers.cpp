#include <bits/stdc++.h>
using namespace std;

// check if all digits in a string are <= limit
bool allDigitsWithinLimit(string &numStr, int limit)
{
    for (char c : numStr)
    {
        if ((c - '0') > limit)
        {
            return false;
        }
    }
    return true;
}

// Compare two number strings
bool isLessThanOrEqual(const string &a, const string &b)
{
    if (a.length() != b.length())
    {
        return a.length() < b.length();
    }
    return a <= b;
}

long long countTill(long long n, const string &s, int limit)
{
    long long count = 0;
    string nStr = to_string(n);

    queue<string> q;
    if (s[0] != '0')
    {
        q.push(s);
    }

    while (!q.empty())
    {
        string curr = q.front();
        q.pop();

        if (!isLessThanOrEqual(curr, nStr))
            continue;

        if (allDigitsWithinLimit(curr, limit))
        {
            count++;
            for (int d = 0; d <= limit; d++)
            {
                string newNum = to_string(d) + curr;
                if (newNum[0] != '0')
                {
                    q.push(newNum);
                }
            }
        }
    }

    return count;
}

long long numberOfPowerfulInt(long long start, long long finish, int limit, string s)
{
    // integer x is powerful if it ends with s & each digit of x is atMost limit(limit or less)
    // return total no of powerful integrs in range [start, finish]

    // generate numbers like s,_s,_ _s and so on
    return (countTill(finish, s, limit) - countTill(start - 1, s, limit));
}

int main()
{
    long long start = 1;
    long long finish = 6000;
    int limit = 4;
    string s = "124";
    cout << "\nNumber of powerful integers: " << numberOfPowerfulInt(start, finish, limit, s);

    return 0;
}