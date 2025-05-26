#include <bits/stdc++.h>
using namespace std;

int largestPathValue(string colors, vector<vector<int>> &edges)
{
    // n colored nodes
    // m edges
    // color[i] denotes color for ith node
    // Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle
    int n = colors.size();
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);

    for (auto &it : edges)
    {
        graph[it[0]].push_back(it[1]);
        indegree[it[1]]++;
    }

    // dp[i][c] = max number of times color c (0 to 25) appears up to node i
    vector<vector<int>> dp(n, vector<int>(26, 0));
    queue<int> q;

    // Initialize queue with 0 indegree nodes
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int visited = 0;
    int answer = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        visited++;

        int colorIdx = colors[node] - 'a';
        dp[node][colorIdx]++;
        answer = max(answer, dp[node][colorIdx]);

        for (auto neighbor : graph[node])
        {
            for (int c = 0; c < 26; c++)
            {
                dp[neighbor][c] = max(dp[neighbor][c], dp[node][c]);
            }
            if (--indegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    // If not all nodes visited, cycle exists
    return visited == n ? answer : -1;
}

int main()
{
    string colors = ;
    vector<vector<int>> edges = ;

    return 0;
}