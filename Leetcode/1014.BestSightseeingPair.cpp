#include <bits/stdc++.h>
using namespace std;

int bruteForce(vector<int> &values)
{
    // values[i] represents the value of the ith sightseeing spot
    // dist bw 2 such spots: j-i
    // score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j
    // return maximum score of a pair of sightseeing spots
    int n = values.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int score = values[i] + values[j] + i - j;
            maxi = max(maxi, score);
        }
    }
    return maxi;
}

int maxScoreSightseeingPair(vector<int> &values)
{
    // values[i] represents the value of the ith sightseeing spot
    // dist bw 2 such spots: j-i
    // score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j
    // return maximum score of a pair of sightseeing spots
    int maxLeft = values[0] + 0; // Initial maxLeft
    int maxi = INT_MIN;          // Initialize the maximum score
    int n = values.size();
    for (int j = 1; j < n; j++)
    {
        // Calculate score for the current pair
        maxi = max(maxi, maxLeft + values[j] - j);
        // Update maxLeft for the next iteration
        maxLeft = max(maxLeft, values[j] + j);
    }

    return maxi;
}

int main()
{
    vector<int> values = {8, 1, 5, 2, 6};
    cout << "\nBrute: Max value possible is: " << bruteForce(values);
    cout << "\nMax value possible is: " << maxScoreSightseeingPair(values);

    return 0;
}