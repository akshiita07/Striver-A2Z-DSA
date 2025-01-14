// Path: node must occur exactly ONCE and must have an edge between the adjacent nodes
// Degree : indegree(incoming edges) + outdegree(outgoing edges)
// Total degree of graph =2*no of edges

#include <bits/stdc++.h>
using namespace std;

// n nodes/vertices & m edges
// m lines to represent all the m edges between

// MATRIX METHOD TO STORE GRAPH: adjacency matrix[n+1][n+1]: whenever edge mark 1 & fill others with 0
// space: n*n =O(n^2)  -> costly + many sparse
int main()
{
    int n;
    int m;
    cin >> n >> m;
    int adj[n + 1][n + 1];
    for (int i = 0; i < m; i++)
    {
        // for every line we have an edge:
        int u, v;
        cin >> u >> v;
        // for WEIGHTED MATRIX: instead of 1 store the weight
        adj[u][v] = 1;
        adj[v][u] = 1; // mark reverse edge also as 1
    }
}

// LIST METHOD TO STORE GRAPH: adjacency list[n+1]->using array
// space=2*no_of_edges=O(2*E)
int main()
{
    int n;
    int m;
    cin >> n >> m;
    vector<int> adjList(n + 1, 0) for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // for WEIGHTED MATRIX: store a pair (connected_to_edge,weight)
        adjList[u].push_back(v);
        adjList[v].push_back(u); // store reverse edge also
    }
    return 0;
}

// Function to return the adjacency list for each vertex.
vector<vector<int>> printGraph(int V, vector<pair<int, int>> &edges)
{
    // Code here
    vector<vector<int>> ans(V);
    int e = edges.size();
    for (int i = 0; i < e; i++)
    {
        ans[edges[i].first].push_back(edges[i].second);
        // undirected graph so reverse also exists:
        ans[edges[i].second].push_back(edges[i].first);
    }
    return ans;
}