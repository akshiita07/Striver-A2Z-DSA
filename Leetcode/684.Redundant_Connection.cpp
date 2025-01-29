#include <bits/stdc++.h>
using namespace std;

bool checkIfCycle(int node, int parent, unordered_set<int> &visited, unordered_map<int, vector<int>> &adjacencyList)
{
    visited.insert(node);
    // go thru all neighbours of node
    for (auto it : adjacencyList[node])
    {
        if (it == parent)
        {
            // parent node is the node from where we reached here so prevent going back
            // skip parent node to avoid backtracking
            continue;
        }
        // if neighbour already visited then cycle might exist:
        if (visited.count(it) || checkIfCycle(it, node, visited, adjacencyList))
        {
            // cycle detected
            return true;
        }
    }
    return false; // no cycle
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    // edges[i] = [ai, bi]: edge between nodes ai and bi in the graph
    // n+1 nodes in graph:
    int n = edges.size();
    // Return edge that can be removed st resulting graph is a tree of n nodes
    //  find and remove the extra edge that caused the cycle.
    unordered_map<int, vector<int>> adjacencyList;
    for (auto &it : edges)
    {
        int ai = it[0];
        int bi = it[1];
        // add edges to adjacencyList
        adjacencyList[ai].push_back(bi);
        adjacencyList[bi].push_back(ai);
        unordered_set<int> visited;
        // if cycle is detected return the current edge
        if (checkIfCycle(ai, -1, visited, adjacencyList) == true)
        {
            return it;
        }
    }
    return {}; // when no cycle detected
}

int main()
{
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> ans = findRedundantConnection(edges);
    cout << "Ans\n";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}