#include <bits/stdc++.h>
using namespace std;

// O(n²)
int brute_force(vector<int> &fruits, vector<int> &baskets)
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

// O(n√n)
// using the square root decomposition technique.
int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
{
    int n = baskets.size();
    // size of each block= sqrt(n)
    int m = sqrt(n);         
    int section = (n + m - 1) / m; // Number of blocks
    int unPlaced = 0;

    // max basket capacity in each block
    vector<int> maxV(section);
    for (int i = 0; i < n; i++)
    {
        maxV[i / m] = max(maxV[i / m], baskets[i]);
    }

    for (auto it : fruits)
    {
        int placed = 0;

        // Go block by block
        for (int sec = 0; sec < section; sec++)
        {
            if (maxV[sec] < it)
            {
                continue; // All baskets in this block too small
            }

            int blockUpdatedMax = 0;
            for (int i = 0; i < m; i++)
            {
                int pos = sec * m + i; 
                if (pos < n)
                {
                    if (!placed && baskets[pos] >= it)
                    {
                        baskets[pos] = 0; 
                        placed = 1; // Mark basket as used
                    }
                    blockUpdatedMax = max(blockUpdatedMax, baskets[pos]);
                }
            }

            maxV[sec] = blockUpdatedMax;

            if (placed){
                break; 
            }
        }

        // If not placed, increase count
        unPlaced += (placed == 0);
    }

    return unPlaced;
}

int main()
{
    vector<int> fruits = {4, 2, 5};
    vector<int> baskets = {3, 5, 4};
    int ans = numOfUnplacedFruits(fruits, baskets);
    cout << "\nAns is: " << ans;

    return 0;
}