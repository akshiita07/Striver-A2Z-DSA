#include <bits/stdc++.h>
using namespace std;

int magnificentSets(int n, vector<vector<int>> &edges)
{
    // nodes in undirected graph from 1 to n
    // edges[i] = [ai, bi] : bidirectional edge between nodes ai and bi
    // Divide nodes of the graph into m groups st: Each node in the graph belongs to exactly one group, pair connected by [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.
    // Return maximum number of groups (maximum m) else Return -1 if impossible to group nodes
    vector<vector<int>> adjacencyList(n);
    // build the adj list:
    for (auto &it : edges)
    {
        // bidirectional edges:
        // we are given 1 based indexing so converted by -1:
        adjacencyList[it[0] - 1].push_back(it[1] - 1);
        adjacencyList[it[1] - 1].push_back(it[0] - 1);
    }
    vector<int> depth(n, 0); // stores the maximum depth of the BFS traversal

    // bfs traversal for each node :
    for (int i = 0; i < n; i++)
    {
        queue<int> qu;
        qu.push(i);
        vector<int> dist(n, 0);
        dist[i] = 1;      // dist from starting node
        int maxDepth = 1; // max dist reached during bfs
        int root = i;     // min node index
        while (!qu.empty())
        {
            int node = qu.front();
            qu.pop();
            root = min(root, node); // update root as minimum index
            // traverse neighbours:
            for (auto it : adjacencyList[node])
            {
                if (dist[it] == 0)
                {
                    dist[it] = dist[node] + 1;
                    maxDepth = max(maxDepth, dist[it]);
                    qu.push(it);
                }
                else if (abs(dist[it] - dist[node]) != 1)
                {
                    // does not satisfy cnd
                    return -1;
                }
            }
        }
        depth[root] = max(depth[root], maxDepth);
    }
    return accumulate(depth.begin(), depth.end(), 0); // total sum of depth values
}

int main()
{
    int n = 6;
    vector<vector<int>> edges = {{1, 2}, {1, 4}, {1, 5}, {2, 6}, {2, 3}, {4, 6}};
    cout << "\nMaximum number of groups= " << magnificentSets(n, edges);

    return 0;
}