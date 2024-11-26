#include <bits/stdc++.h>
using namespace std;

int findChampion(int n, vector<vector<int>> &edges)
{
    // teams numbered from 0 to n-1
    // arrow [i,j] from i to j means team j is weaker than team i
    // champion node must have no incoming edges so degree==0
    // & only 1 champion node if more than 1 have degree 0 then cannot be calculated so return -1

    vector<int> inDegree(n, 0); // in-degree array

    // Step 2: Calculate in-degrees
    for (const auto &it : edges)
    {
        inDegree[it[1]] += 1; // 2nd elem pe arrow hai so inc its indegree
    }

    // Step 3: Find nodes with in-degree 0
    int champion = -1; // Default no champion
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            if (champion != -1)
            {
                // More than one node with in-degree 0, no unique champion
                return -1;
            }
            champion = i;
        }
    }

    return champion;
}

int main()
{
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}};
    cout << "\nThe winning team is: " << findChampion(n, edges);

    return 0;
}