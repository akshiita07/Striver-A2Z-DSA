#include <bits/stdc++.h>
using namespace std;

// Converts the list of edges into an adjacency list
void build(vector<vector<int>> &adjacencyList, vector<vector<int>> &edges, int n)
{
    for (auto it : edges)
    {
        // to create adjacency list:
        adjacencyList[it[0]].push_back(it[1]);
        adjacencyList[it[1]].push_back(it[0]);
    }
}

// Find farthest node and its distance from a starting node
void get(pair<int, int> &farthestNode, vector<vector<int>> &adjacencyList, int node, int distance, vector<int> &visited)
{
    int d = farthestNode.second;
    visited[node] = 1;
    if (distance > d)
    {
        farthestNode.second = distance;
        farthestNode.first = node;
    }
    for (auto it : adjacencyList[node])
    {
        if (!visited[it])
        {
            get(farthestNode, adjacencyList, it, distance + 1, visited);
        }
    }
}
// Compute minimum diameter after merging two trees.
int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
{
    //  length of the longest path between any two nodes in the tree
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;
    vector<vector<int>> adj1(n), adj2(m);

    // build adjacency list:
    build(adj1, edges1, n);
    build(adj2, edges2, m);

    // find diameters of trees:

    // for first tree
    // farthest node from node 0:
    vector<int> visited(n);
    pair<int, int> p1 = {-1, INT_MIN};
    get(p1, adj1, 0, 0, visited);
    visited = vector<int>(n, 0);
    pair<int, int> p2 = {-1, INT_MIN};
    get(p2, adj1, p1.first, 0, visited);

    int d1 = p2.second;

    // for other tree
    p1 = {-1, INT_MIN};
    visited = vector<int>(m, 0);
    get(p1, adj2, 0, 0, visited);
    p2 = {-1, INT_MIN};
    visited = vector<int>(m, 0);
    get(p2, adj2, p1.first, 0, visited);

    int d2 = p2.second;
    if (edges1.empty())
    {
        d1 = 0;
    }
    if (edges2.empty())
    {
        d2 = 0;
    }

    // find max of these 3: d1, d2, (d1+1)/2+(d2+1)/2+1
        int mergedDiameter = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;

        return max({d1, d2, mergedDiameter});
}

int main()
{
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 3}};
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}};
    cout << "\nMin dia is: " << minimumDiameterAfterMerge(edges1, edges2);

    return 0;
}
