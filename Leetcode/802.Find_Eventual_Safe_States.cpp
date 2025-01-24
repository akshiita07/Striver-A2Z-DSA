#include <bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    // directed graph of n nodes
    int n = graph.size();
    // graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

    // terminal node if there are no outgoing edges: jinke liye graph[i]={empty}
    // safe node if every possible path starting from that node leads to a terminal node/safe node

    vector<vector<int>> reverseGraph(n);
    vector<int> inDegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        // build reverse graph & calculate indegree:
        for (auto it : graph[i])
        {
            reverseGraph[it].push_back(i);
            inDegree[i]++;
        }
    }

    queue<int> qu; // add all nodes with no incoming edges ie terminal nodes
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            qu.push(i);
        }
    }
    vector<int> ans;
    while (!qu.empty())
    {
        int node = qu.front();
        qu.pop();
        ans.push_back(node);
        for (auto it : reverseGraph[node])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
            {
                qu.push(it);
            }
        }
    }
    // Return array containing all the safe nodes of the graph sorted in ascending order
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<int> ans = eventualSafeNodes(graph);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}