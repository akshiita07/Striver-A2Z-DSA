#include <bits/stdc++.h>
using namespace std;

int minCostToMakeBasketsEqual(vector<int> &basket1, vector<int> &basket2)
{
    unordered_map<int, int> freq;
    int smallestFruit = INT_MAX;

    // Count fruits in basket1
    for (int fruit : basket1)
    {
        freq[fruit]++;
        smallestFruit = min(smallestFruit, fruit);
    }

    // Subtract fruits from basket2
    for (int fruit : basket2)
    {
        freq[fruit]--;
        smallestFruit = min(smallestFruit, fruit);
    }

    // Collect fruits that are unbalanced
    vector<int> needToSwap;
    for (auto it : freq)
    {
        int fruit = it.first;
        int count = it.second;

        // If odd mismatch, we cannot fix it
        if (count % 2 != 0)
        {
            return -1;
        }

        // Add half the extra fruits to swap list
        for (int i = 0; i < abs(count) / 2; i++)
        {
            needToSwap.push_back(fruit);
        }
    }

    // Sort to get smallest values first
    sort(needToSwap.begin(), needToSwap.end());

    long long cost = 0;
    int swapsNeeded = needToSwap.size() / 2;

    for (int i = 0; i < swapsNeeded; i++)
    {
        // For each swap, pick the cheaper option
        cost += min(needToSwap[i], 2 * smallestFruit);
    }

    return cost;
}

int main()
{
    vector<int> &basket1 = {};
    vector<int> &basket2 = {};
    cout<<minCostToMakeBasketsEqual(basket1,basket2);

    return 0;
}
