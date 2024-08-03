#include <bits/stdc++.h>
using namespace std;
// SAME AS Aggressive Cows PROBLEM

// FNC- TIME:O(n)
bool ballsCanBePlaced(vector<int> &position, int m, int gap)
{
    int noOfBalls = 1;
    int posBall = position[0];
    int n = position.size();
    for (int i = 1; i < n; i++)
    {
        if (position[i] - posBall >= gap)
        {
            noOfBalls++;
            posBall = position[i];
        }
        else
        {
            continue;
        }

        if (noOfBalls >= m)
        {
            return true;
        }
    }
    return false;
}

// BINARY SEARCH: TIME-O(n)->fnc*O(log2(max-min))-->binary search
int maxDistance(vector<int> &position, int m)
{
    int n = position.size();
    sort(position.begin(), position.end());
    int low = 1;
    int high = position[n - 1] - position[0]; // max-min
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (ballsCanBePlaced(position, m, mid))
        {
            ans = mid;
            low = mid + 1; // find max value
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;     //or return high
}

int main()
{
    vector<int> position = {1, 2, 3, 4, 7};
    int m = 3;
    cout << "\nThe max possible min distance between any 2 balls is: " << maxDistance(position, m);

    return 0;
}