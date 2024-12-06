#include <bits/stdc++.h>
using namespace std;

int maxCount(vector<int> &banned, int n, int maxSum)
{
    // range of chosen integers: 1 to n & choose only once
    // chosen int must not be in banned array
    // sum of chosen integers<=maxSum
    set<int> setOfBannedNumbers;
    for (int i = 0; i < banned.size(); i++)
    {
        setOfBannedNumbers.insert(banned[i]);
    }
    int count = 0;
    int currentSum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (setOfBannedNumbers.find(i) == setOfBannedNumbers.end() && (currentSum + i <= maxSum))
        {
            count++;
            currentSum += i;
        }
    }
    return count;
}

int main()
{
    vector<int> banned = {1, 6, 5};
    int n = 5;
    int maxSum = 6;
    cout << "\nPossible count: " << maxCount(banned, n, maxSum);

    return 0;
}