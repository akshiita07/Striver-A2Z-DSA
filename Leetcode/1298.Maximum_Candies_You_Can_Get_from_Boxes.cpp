#include <bits/stdc++.h>
using namespace std;

int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys, vector<vector<int>> &containedBoxes, vector<int> &initialBoxes)
{
    // n boxes
    // status[i]=1 ith box is open = 0 ith box is closed,
    // candies[i] = number of candies in the ith box,
    // keys[i] = list of the labels of the boxes you can open after opening the ith box.
    // containedBoxes[i] = list of the boxes you found inside the ith box.
    // initialBoxes = contains the labels of the boxes you initially have
    // Return the maximum number of candies you can get
    int n = status.size();
    vector<bool> boxFound(n, false);
    vector<bool> visited(n, false);
    vector<bool> hasKey(n, false);
    queue<int> q;

    for (auto it : initialBoxes)
    {
        boxFound[it] = true;
        q.push(it);
    }

    int totalCandies = 0;

    while (!q.empty())
    {
        int box = q.front();
        q.pop();
        // If box is not open and we don’t have the key, skip
        if (!status[box] && !hasKey[box])
        {
            continue;
        }
        // skip if already processed
        if (visited[box])
        {
            continue;
        }
        // now visited:
        visited[box] = true;

        // Collect candies
        totalCandies += candies[box];

        // Collect keys
        for (int k : keys[box])
        {
            hasKey[k] = true;
            if (boxFound[k] && !visited[k])
            {
                q.push(k);
            }
        }

        // Collect contained boxes
        for (int cb : containedBoxes[box])
        {
            boxFound[cb] = true;
            if (!visited[cb])
            {
                q.push(cb);
            }
        }
    }

    return totalCandies;
}

int main()
{
    vector<int> &status = {};
    vector<int> &candies = {};
    vector<vector<int>> &keys = {};
    vector<vector<int>> &containedBoxes = {};
    vector<int> &initialBoxes = {};
    cout << "\nMax candies: " << maxCandies(status, candies, keys, containedBoxes, initialBoxes);

    return 0;
}