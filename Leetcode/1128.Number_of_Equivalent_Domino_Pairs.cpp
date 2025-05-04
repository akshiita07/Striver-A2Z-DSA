#include <bits/stdc++.h>
using namespace std;

// dominoes[i] = [a, b] equiv to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c)
// Return number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j]

int brute_force(vector<vector<int>> &dominoes)
{
    int n = dominoes.size();
    int count = 0;
    // each list has then 2 elements
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // check condition:
            if ((dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1]) || dominoes[i][0] == dominoes[j][1] && dominoes[i][1] == dominoes[j][0])
            {
                count++;
            }
        }
    }
    return count;
}

// optimal approach using hashMap
int numEquivDominoPairs(vector<vector<int>> &dominoes)
{
    int n = dominoes.size();
    int count = 0;
    unordered_map<int, int> hashMap;
    for (int i = 0; i < n; i++)
    {
        int firstEle = dominoes[i][0];
        int secEle = dominoes[i][1];
        // add elements in a sorted order
        if (firstEle > secEle)
        {
            swap(firstEle, secEle);
        }
        // form a key out of these 2 elements
        int key = (firstEle * 10) + secEle;
        count += hashMap[key];
        hashMap[key]++;
    }
    return count;
}

int main()
{
    vector<vector<int>> dominoes = {{1, 2}, {1, 2}, {1, 1}, {1, 2}, {2, 2}, {2, 1}};
    cout << "\nbrute_force Number of Equivalent Domino Pairs: " << brute_force(dominoes);
    cout << "\nNumber of Equivalent Domino Pairs: " << numEquivDominoPairs(dominoes);

    return 0;
}