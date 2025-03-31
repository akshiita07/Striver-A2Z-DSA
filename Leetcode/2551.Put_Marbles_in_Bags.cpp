#include <bits/stdc++.h>
using namespace std;

long long putMarbles(vector<int> &weights, int k)
{
    // k bags
    // weights: weight of ith marble
    // divide marbles into k bags st 1. no bag is empty 2. all indices between i & jth marble should be in same bag 3. cost of bag=weight[i]+weight[j]
    // return difference between cost of MAX & MIN score of k-th bags
    int n = weights.size();
    if (k == 1)
    {
        // only 1 bag
        return 0;
    }
    vector<int> sums;
    for (int i = 0; i < n - 1; i++)
    {
        sums.push_back(weights[i] + weights[i + 1]);
    }
    // sort these pair wise sums:
    sort(sums.begin(), sums.end());
    long long minCost = 0;
    long long maxCost = 0;
    for (int i = 0; i < k - 1; i++)
    {
        minCost += sums[i];
        maxCost += sums[n - 2 - i];
    }
    return maxCost - minCost;
}

int main()
{
    vector<int> weights = {1, 3, 5, 1};
    int k = 2;
    cout << "\nMinimum number of bags required: " << putMarbles(weights, k);
    return 0;
}