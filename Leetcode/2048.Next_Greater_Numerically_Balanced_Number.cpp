#include <bits/stdc++.h>
using namespace std;

int countOccurrenceOfDigit(int x, int d)
{
    string number = to_string(x);
    int n = number.length();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if ((number[i] - '0') == d)
        {
            count++;
        }
    }
    return count;
}

int nextBeautifulNumber(int n)
{
    // every digit d in number x mmust be repeated exactly d times
    // return smallest balanced number STRICTLY GREATER than n
    int x = n + 1;
    while (true)
    {
        string number = to_string(x);
        int n = number.length();
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            int d = number[i] - '0';
            if (countOccurrenceOfDigit(x, d) != d)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return x;
        }
        x++;
    }
    return -1; // couldnt find
}

int main()
{

    return 0;
}