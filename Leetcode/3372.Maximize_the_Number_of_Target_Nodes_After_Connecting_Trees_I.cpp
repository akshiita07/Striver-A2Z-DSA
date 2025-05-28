#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &graph, int start, int k)
{
    int n = graph.size();
    vector<int> distance(n, -1);
    queue<int> q;
    q.push(start);
    distance[start] = 0;

    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (distance[node] > k)
        {
            continue;
        }
        count++;
        for (auto it : graph[node])
        {
            if (distance[it] == -1)
            {
                distance[it] = distance[node] + 1;
                q.push(it);
            }
        }
    }
    return {count};
}

vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
{
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;

    vector<vector<int>> tree1(n);
    vector<vector<int>> tree2(m);
    for (auto &it : edges1)
    {
        tree1[it[0]].push_back(it[1]);
        tree1[it[1]].push_back(it[0]);
    }
    for (auto &it : edges2)
    {
        tree2[it[0]].push_back(it[1]);
        tree2[it[1]].push_back(it[0]);
    }

    // nodes within k for each node in tree1
    vector<int> reachTree1(n);
    for (int i = 0; i < n; i++)
    {
        reachTree1[i] = bfs(tree1, i, k)[0];
    }

    // nodes within k-1 for each node in tree2
    vector<int> reachTree2(m);
    for (int i = 0; i < m; i++)
    {
        reachTree2[i] = bfs(tree2, i, k - 1)[0];
    }

    // max from tree2 for every query
    int maxTree2 = *max_element(reachTree2.begin(), reachTree2.end());

    // Answer = best node in tree2 + self reach in tree1
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        result[i] = reachTree1[i] + maxTree2;
    }

    return result;
}

int main()
{

    return 0;
}