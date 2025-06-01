#include <bits/stdc++.h>
using namespace std;

int distributeCandies(int n, int limit)
{
    //   distribute n candies among 3 children such that no child gets more than limit candies
    int count = 0;
    for (int i = 0; i <= limit; i++)
    {
        for (int j = 0; j <= limit; j++)
        {
            for (int k = 0; k <= limit; k++)
            {
                if (i + j + k == n)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{
    int n = 5;
    int limit = 2;
    cout << "\nNumber of ways are= " << distributeCandies(n, limit);

    return 0;
}