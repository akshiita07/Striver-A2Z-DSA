#include <bits/stdc++.h>
using namespace std;

// count distance from a start node to all its reachable nodes
void countDistance(vector<int> &edges, int start, vector<int> &dist)
{
    int distance = 0;
    while (start != -1 && dist[start] == -1)
    {
        dist[start] = distance++;
        start = edges[start];
    }
}

int closestMeetingNode(vector<int> &edges, int node1, int node2)
{
    // Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized.
    int n = edges.size();

    // Initialize distances from both nodes with -1 (unvisited)
    vector<int> dist1(n, -1), dist2(n, -1);

    countDistance(edges, node1, dist1);
    countDistance(edges, node2, dist2);

    int result = -1;
    int minDist = INT_MAX;

    //  find the one reachable from both with minimal max distance
    for (int i = 0; i < n; i++)
    {
        if (dist1[i] != -1 && dist2[i] != -1)
        {
            int maxDist = max(dist1[i], dist2[i]);
            if (maxDist < minDist)
            {
                minDist = maxDist;
                result = i;
            }
        }
    }

    return result;
}

int main()
{

    return 0;
}