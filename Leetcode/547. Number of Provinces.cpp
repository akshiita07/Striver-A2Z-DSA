#include <bits/stdc++.h>
using namespace std;

// Time: O(n):outer for loop thru visited array  +  O(v+2e):only dfs call made for provinces
// Space: O(n):visited + O(n):recursive stack space for DFS

class Solution
{
public:
    void dfs_traversal(int node, vector<int> &visited, vector<vector<int>> &isConnected)
    {

        visited[node] = 1;
        cout << node << " ";
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (isConnected[node][i])
            {
                if (!visited[i])
                {
                    dfs_traversal(i, visited, isConnected);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // n cities
        // Return the total no of provinces ie a group of directly/indirectly connected cities
        int n = isConnected.size();
        int provinces = 0;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs_traversal(i, visited, isConnected);
                // this is new province so inc count:
                provinces++;
            }
        }
        return provinces;
    }
};