#include <bits/stdc++.h>
using namespace std;

// 1. find connected components of graph using BFS:
void bfs(int start, unordered_map<int, vector<int>> &graph, unordered_set<int> &visited, vector<int> &component)
{
    queue<int> qu;
    qu.push(start);
    visited.insert(start);
    // loop:
    while (!qu.empty())
    {
        int node = qu.front();
        qu.pop();
        component.push_back(node);
        for (auto it : graph[node])
        {
            if (!visited.count(it))
            {
                visited.insert(it);
                qu.push(it);
            }
        }
    }
}

int countCompleteComponents(int n, vector<vector<int>> &edges)
{
    // vertices from 0 to n-1
    // edges[i] = [ai, bi]: undirected edge connecting vertices ai and bi
    // Return number of complete connected components of the graph
    // 1. BFS:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    for (auto &it : edges)
    {
        int u = it[0];
        int v = it[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ans = 0;

    // 2. for each connected component: count no of nodes and edges
    for (int i = 0; i < n; i++)
    {
        if (!visited.count(i))
        {
            vector<int> component;
            bfs(i, graph, visited, component);
            int size = component.size();
            // 3. connected component is COMPLETE if no of edges=no of nodes(no of nodes-1)/2
            int reqdEdges = (size * (size - 1)) / 2;
            int actualEdges = 0;
            for (auto it : component)
            {
                actualEdges += graph[it].size();
            }
            // since each edge is counted two times so divide by 2:
            actualEdges = actualEdges / 2;
            if (actualEdges == reqdEdges)
            {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    cout << "\nnumber of complete connected components of the graph= " << countCompleteComponents(n, edges) << endl;

    return 0;
}