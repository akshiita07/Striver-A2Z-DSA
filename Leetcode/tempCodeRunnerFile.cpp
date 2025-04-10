#include <bits/stdc++.h>
using namespace std;

long long countTill(long long n, string &s, int limit)
{
    // count all powerful integers <= n
    // generate all possible numbers like s, _s, _ _s and so on
    // check if it is less than or equal to n and each digit is atMost limit

    long long count = 0;
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        // generate number like s, _s, _ _s and so on
        string temp = s.substr(i);
        long long num = stoll(temp);    
        if (num <= n)
        {
            count++;
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