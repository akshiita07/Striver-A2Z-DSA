#include <bits/stdc++.h>
using namespace std;

int maxOperations(string s)
{
    int n = s.length();
    int noOfOnes = 0;
    int noOfOperations = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            while (s[i + 1] == '0' && (i + 1) < n)
            {
                // move s[i] to right until end of string or another 1
                i++;
            }
            noOfOperations += noOfOnes;
        }
        else
        {
            // if 0:
            noOfOnes++;
        }
    }
    return noOfOperations;
}

int main()
{

    return 0;
}