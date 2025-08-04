#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> &fruits)
{
    // fruits[i] is the type of fruit the ith tree produces
    // 2 baskets
    // each basket can hold only ONE type of fruit
    // return max no of fruits u can collect
    unordered_map<int, int> fruitCount;
    int i = 0;
    int n = fruits.size();
    int maxFruits = 0;
    for (int j = 0; j < n; j++)
    {
        fruitCount[fruits[j]]++;
        // if more than 2 types of fruits then slide window from left
        while (fruitCount.size() > 2)
        {
            fruitCount[fruits[i]]--;
            // if empty then remove:
            if (fruitCount[fruits[i]] == 0)
            {
                fruitCount.erase(fruits[i]);
            }
            i++;
        }
        maxFruits = max(maxFruits, j - i + 1);
    }
    return maxFruits;
}

int main()
{
    vector<int> fruits = {1, 2, 3, 2, 2};
    cout << "Total number of fruits: " << totalFruit(fruits) << endl;

    return 0;
}