#include <bits/stdc++.h>
using namespace std;

long long distributeCandies(int n, int limit)
{
    //   distribute n candies among 3 children such that no child gets more than limit candies
    // Hint 1
    // We can enumerate the number of candies of one particular child, let it be i which means 0 <= i <= min(limit, n).
    long long count = 0;
    for (int i = 0; i <= min(n, limit); i++)
    {
        // Hint 2
        // Suppose the 2nd child gets j candies. Then 0 <= j <= limit and i + j <= n.
        int minJ = max(0, n - limit - i);
        int maxJ = min(limit, n - i);
        // Hint 3
        // The 3rd child will hence get n - i - j candies and we should have 0 <= n - i - j <= limit.
        if (minJ <= maxJ)
        {
            count += (maxJ - minJ + 1);
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