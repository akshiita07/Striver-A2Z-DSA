#include <bits/stdc++.h>
using namespace std;

// fnc to calculate how many days reqd to ship with this capacity
int checkHowManyDays(vector<int> &weights, int capacity)
{
    int daysReqd = 1; // on first day
    int n = weights.size();
    int sumLoad = 0;

    for (int i = 0; i < n; i++)
    {
        // add element & check sumLoad
        // sumLoad of weights<=capacity
        if ((sumLoad + weights[i]) <= capacity)
        {
            // added on same day
            sumLoad = sumLoad+weights[i];
        }
        else
        {
            // sumLoad>capacity: this capacity would not be possible
            // so change day then try adding
            daysReqd++;
            sumLoad = weights[i];       //start from new weight so no +=
        }
    }
    return daysReqd;
}

// BINARY SEARCH: TIME-O(log2(sum of all  elem-max ele+1)-->bin search) * O(n)-->calculating days
int shipWithinDays(vector<int> &weights, int days)
{
    int low = *max_element(weights.begin(), weights.end());   // at min load MAX weight each day
    int high = accumulate(weights.begin(), weights.end(), 0); // at max load sumLoad of all weights on day1
    cout << "\nMin capacity of ship ranges from " << low << " to " << high;
    int minCapacity = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int daysPossible = checkHowManyDays(weights, mid);

        if (daysPossible <= days)
        {
            minCapacity = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return minCapacity;
    // or return low also
}

int main()
{
    vector<int> weights1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 15
    int d1 = 5;
    cout << "\nThe minimum capacity of ship to load all weights in " << d1 << " days is: " << shipWithinDays(weights1, d1);
    vector<int> weights2 = {3, 2, 2, 4, 1, 4}; // 6
    int d2 = 3;
    cout << "\nThe minimum capacity of ship to load all weights in " << d2 << " days is: " << shipWithinDays(weights2, d2);

    return 0;
}