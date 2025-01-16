#include <bits/stdc++.h>
using namespace std;

// TIME: O(n)+O(2*e)
// SPACE: O(n):adjacency list +  O(n):visited + O(n):recursion stack space = O(3n)

// go depth wise: RECURSION
void dfs_traversal(int node, vector<vector<int>> &adjacencyList, vector<int> &visited)
{
    visited[node] = 1;
    cout << node; // or store in a list DFS TRAVERSAL
    for (auto it : adjacencyList[node])
    {
        // go depth wise:
        if (!visited[it])
        {
            dfs_traversal(it, adjacencyList, visited);
        }
    }
}
void dfs(int V, vector<vector<int>> adjacencyList)
{
    vector<int> visited(n, 0);
    // mark first node as visited:
    visited[0] = 1;
    dfs_traversal(0, adjacencyLis, visited);
}

// actual:
void dfs_traversal(int node, vector<int> &dfs, vector<vector<int>> &adj, vector<int> &visited)
{
    visited[node] = 1;
    // cout << node; // or store in a list DFS TRAVERSAL
    dfs.push_back(node);
    for (auto it : adj[node])
    {
        // go depth wise:
        if (!visited[it])
        {
            dfs_traversal(it, dfs, adj, visited);
        }
    }
}
vector<int> dfsOfGraph(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> dfs;
    vector<int> visited(n, 0);
    // mark first node as visited:
    visited[0] = 1;
    dfs_traversal(0, dfs, adj, visited);
    return dfs;
}