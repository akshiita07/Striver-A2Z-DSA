#include <bits/stdc++.h>
using namespace std;

// go equivalent edges in the breadth
// traversal changes depending upon the starting node
// implementation: queue

// V:no of nodes
// adjacency list of edges given

// Time: O(n):queue + O(2*e):total degree for each node == O(n)+O(2e)
// Space: O(n)queue + O(n)vector for bfs ans + O(n):visited array = O(3n)
void bfs(int V, vector<vector<int>> adjacencyList)
{
    vector<int> visited(n, 0);
    queue<int> qu;
    qu.push(0);
    // mark first node as visited:
    visited[0] = 1;

    // until qu is empty:
    while (!qu.empty())
    {
        // take out first queue element
        int node = qu.front();
        cout << qu.front(); // bfs traversal   (or add in a list)
        // pop from queue:
        qu.pop();
        // traverse neighbours of node:
        for (auto it : adjacencyList[node])
        {
            // add them to queue if NOT already visited:
            if (!visited[it])
            {
                qu.push(it);
            }
            // add them to visited array:
            visited[it] = 1;
        }
    }
}

vector<int> bfsOfGraph(vector<vector<int>> &adj)
{
    // Code here
    int n = adj.size();
    vector<int> visited(n, 0);
    queue<int> qu;
    qu.push(0);
    // mark first node as visited:
    visited[0] = 1;

    vector<int> bfs;
    // until qu is empty:
    while (!qu.empty())
    {
        // take out first queue element
        int node = qu.front();
        // cout << qu.front(); // bfs traversal   (or add in a list)
        // pop from queue:
        bfs.push_back(node);
        qu.pop();
        // traverse neighbours of node:
        for (auto it : adj[node])
        {
            // add them to queue if NOT already visited:
            if (!visited[it])
            {
                qu.push(it);
            }
            // add them to visited array:
            visited[it] = 1;
        }
    }

    return bfs;
}