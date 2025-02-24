#include <bits/stdc++.h>
using namespace std;

int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
{
    // edges[i] = [ai, bi] indicates : an edge between nodes ai and bi in the tree
    // amount[i] represents: price needed to open gate at node i, if amount[i] is negative,,cash reward obtained on opening the gate at node i, otherwise.
    int n = amount.size();
    // Adjacency list for the tree
    vector<vector<int>> tree(n);
    for (auto &it : edges)
    {
        tree[it[0]].push_back(it[1]);
        tree[it[1]].push_back(it[0]);
    }

    vector<int> bobTime(n, -1);   // Stores the time Bob reaches each node
    vector<int> aliceTime(n, -1); // Stores the time Alice reaches each node
    vector<int> path;             // To track Bob's path

    // 1. **Find Bob's path to root and his arrival time at each node**
    function<bool(int, int, int)> findBobPath = [&](int node, int parent, int time)
    {
        if (node == bob)
        {
            bobTime[node] = time;
            path.push_back(node);
            return true;
        }
        for (int neighbor : tree[node])
        {
            if (neighbor != parent && findBobPath(neighbor, node, time + 1))
            {
                bobTime[node] = time;
                path.push_back(node);
                return true;
            }
        }
        return false;
    };
    findBobPath(0, -1, 0); // Start DFS from node 0

    // Mark Bob's arrival time for each node in the path
    for (int i = 0; i < path.size(); i++)
    {
        bobTime[path[i]] = i;
    }

    // 2. **DFS for Alice to find the maximum profit**
    int maxProfit = INT_MIN;
    function<void(int, int, int, int)> dfsAlice = [&](int node, int parent, int time, int currProfit)
    {
        aliceTime[node] = time;

        // Handle amount logic
        if (bobTime[node] == -1 || time < bobTime[node])
        {
            currProfit += amount[node]; // Alice gets full amount
        }
        else if (time == bobTime[node])
        {
            currProfit += amount[node] / 2; // Alice and Bob share
        } // Else, Bob already took it, so Alice gets nothing

        // If leaf node, update maxProfit
        bool isLeaf = true;
        for (int neighbor : tree[node])
        {
            if (neighbor != parent)
            {
                isLeaf = false;
                dfsAlice(neighbor, node, time + 1, currProfit);
            }
        }
        if (isLeaf)
            maxProfit = max(maxProfit, currProfit);
    };

    dfsAlice(0, -1, 0, 0); // Start DFS for Alice from node 0

    return maxProfit;
}

int main()
{
    vector<vector<int>> &edges = ;
    int bob = ;
    vector<int> &amount = ;
    cout << mostProfitablePath(edges, bob, amount);

    return 0;
}