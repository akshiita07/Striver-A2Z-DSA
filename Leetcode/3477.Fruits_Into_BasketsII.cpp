//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
{
    int n = fruits.size();
    // fruits[i]=quantity of ith fruit
    // baskets[j]=capacity of jth basket
    // capacity of basket >= quantity of fruit
    // basket can hold only 1 type of fruit
    // Return the number of fruit types that remain unplaced
    // iterate thru each fruit & check if it can be placed in basket or not
    int unplaced = 0;
    for (int i = 0; i < n; i++)
    {
        bool placed = false;
        for (int j = 0; j < baskets.size(); j++)
        {
            if (baskets[j] >= fruits[i])
            {
                placed = true;
                // remove this basket now:
                baskets.erase(baskets.begin() + j);
                break;
            }
        }
        if (!placed)
        {
            unplaced++;
        }
    }
    return unplaced;
}

int main()
{
    vector<int> fruits = {4, 2, 5};
    vector<int> baskets = {3, 5, 4};
    int ans = numOfUnplacedFruits(fruits, baskets);
    cout << "\nAns is: " << ans;

    return 0;
}