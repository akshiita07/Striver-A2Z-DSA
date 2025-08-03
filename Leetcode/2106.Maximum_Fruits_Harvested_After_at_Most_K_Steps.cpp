// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int getSum(int left, int right, vector<int> &prefix)
{
    return prefix[right + 1] - prefix[left];
}

int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
{
    // fruits[i] = [positioni, amounti] ie amount of i no of fruits at position i
    // initially at position startPos
    // can walk atmost k steps
    // Return the maximum total number of fruits you can harvest
    int n = fruits.size();
    vector<int> positions;
    vector<int> amounts;

    for (auto it : fruits)
    {
        positions.push_back(it[0]);
        amounts.push_back(it[1]);
    }

    // compute prefix sum of fruit amounts:
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + amounts[i];
    }

    int ans = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < n)
        {
            int left = positions[i];
            int right = positions[j];
            int steps = min(abs(startPos - left), abs(startPos - right)) + (right - left);
            if (steps > k)
            {
                break;
            }
            j++;
        }
        if(j>0){
            ans=max(ans, getSum(i, j-1, prefix));
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> fruits = {{0, 9}, {4, 1}, {5, 7}, {6, 2}, {7, 4}, {10, 9}};
    int startPos = 5;
    int k = 4;
    cout << "\nmaximum total number of fruits you can harvest= " << maxTotalFruits(fruits, startPos, k);

    return 0;
}