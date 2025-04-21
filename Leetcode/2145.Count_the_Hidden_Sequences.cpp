#include <bits/stdc++.h>
using namespace std;

int numberOfArrays(vector<int> &differences, int lower, int upper)
{
    int n = differences.size();
    // differences tells differnece between consecutive elements of a hidden sequence of n+1 length
    // differences[i] = hidden[i + 1] - hidden[i]
    // inclusive range of values [lower, upper] that the hidden sequence can contain
    // Return the number of possible hidden sequences
    long long sum = 0;
    long long maxPrefix = 0;
    long long minPrefix = 0;
    for (auto it : differences)
    {
        sum += it;
        maxPrefix = max(maxPrefix, sum);
        minPrefix = min(minPrefix, sum);
    }
    long long reqdRange = maxPrefix - minPrefix;
    long long availableRange = upper - lower;
    if (reqdRange > availableRange)
    {
        return 0;
    }
    return availableRange - reqdRange + 1;
}

int main()
{
    vector<int> differences = {3, -4, 5, 1, -2};
    int lower = -4;
    int upper = 5;
    cout << "\nnumber of arrays= " << numberOfArrays(differences, lower, upper);

    return 0;
}