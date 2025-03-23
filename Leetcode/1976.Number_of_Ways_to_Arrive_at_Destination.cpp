#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int countPaths(int n, vector<vector<int>> &roads)
{
    // roads[i] = [ui, vi, timei] : a road bw intersections ui and vi + takes timei mins to travel
    // how many ways u can travel from intersec 0 to intersec n - 1 in the shortest amount of time
    // Dijkstra's Algorithm for finding the shortest path
    vector<vector<pair<int, int>>> graph(n);
    for (auto &it : roads)
    {
        int u = it[0];
        int v = it[1];
        int time = it[2];
        graph[u].push_back({v, time});
        graph[v].push_back({u, time});
    }
    vector<long long> dist(n, LLONG_MAX);
    vector<int> ways(n, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto [time, node] = pq.top();
        pq.pop();
        if (time > dist[node])
        {
            continue;
        }
        for (auto [neighbour, travelTime] : graph[node])
        {
            long long newTime = time + travelTime;
            if (newTime < dist[neighbour])
            {
                dist[neighbour] = newTime;
                ways[neighbour] = ways[node];
                pq.push({newTime, neighbour});
            }
            else if (newTime == dist[neighbour])
            {
                ways[neighbour] = (ways[neighbour] + ways[node]) % mod;
            }
        }
    }
    return ways[n - 1];
}

int main()
{
    int n = 7;
    vector<vector<int>> roads = {{0, 6, 7},
                                 {0, 1, 2},
                                 {1, 2, 3},
                                 {1, 3, 3},
                                 {6, 3, 3},
                                 {3, 5, 1},
                                 {6, 5, 1},
                                 {2, 5, 1},
                                 {0, 4, 5},
                                 {4, 6, 2}};
    cout << "\nnumber of ways you can arrive at your destination in the shortest amount of time= " << countPaths(n, roads);

    return 0;
}