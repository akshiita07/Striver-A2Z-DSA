#include <bits/stdc++.h>
using namespace std;

// DFS to count even-depth nodes and color the tree
int dfs(int node, int parent, int depth, const vector<vector<int>> &tree, vector<int> &depthParity)
{
    // Color node as 0 (even) or 1 (odd)
    depthParity[node] = depth % 2;

    // Count nodes with even depth (0), since 1 - (depth % 2) is 1 if even, 0 if odd
    int countEven = 1 - (depth % 2);

    for (auto it : tree[node])
    {
        if (it != parent)
        {
            countEven += dfs(it, node, depth + 1, tree, depthParity);
        }
    }
    return countEven;
}

// Build tree from edges, fill parity array, and count even/odd nodes
vector<int> countEvenOdd(const vector<vector<int>> &edges, vector<int> &parity)
{
    int size = edges.size() + 1;
    vector<vector<int>> tree(size);

    for (auto &it : edges)
    {
        tree[it[0]].push_back(it[1]);
        tree[it[1]].push_back(it[0]);
    }

    int evenCount = dfs(0, -1, 0, tree, parity);
    int oddCount = size - evenCount;

    return {evenCount, oddCount};
}

vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
{
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;

    // Get parity (0: even depth, 1: odd depth) for each node
    vector<int> parity1(n);
    vector<int> parity2(m);

    // Count even/odd nodes in both trees
    vector<int> count1 = countEvenOdd(edges1, parity1); // [even, odd]
    vector<int> count2 = countEvenOdd(edges2, parity2); // [even, odd]

    // For each node in tree1, based on its parity, use the matching count1
    // Add the best (max) of even or odd count from tree2
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        int thisNodeParity = parity1[i]; // 0 for even, 1 for odd
        result[i] = count1[thisNodeParity] + max(count2[0], count2[1]);
    }

    return result;
}

int main()
{

    return 0;
}