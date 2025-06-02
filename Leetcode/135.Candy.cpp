#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> &ratings)
{
    int n = ratings.size();
    // each child must have at least one candy
    // children with higher rating must get more candies than their neighbors
    // return minimum candies needed by u

    // give everyone atlease 1 candy:
    vector<int> candies(n, 1);
    // move left to right & assign candies:
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }
    // move right to left & assign candies:
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }
    int ans = 0;
    for (auto it : candies)
    {
        ans += it;
    }
    return ans;
}

int main()
{
    vector<int> ratings = {1, 0, 2};
    cout << "\nMin candies needed: " << candy(ratings);
    return 0;
}