#include <bits/stdc++.h>
using namespace std;

long long dfs(int node, int parent, const vector<vector<int>> &tree, const vector<int> &values, int k, int &ans)
{
    long long sum = values[node]; // Start with the value of the current node

    for (auto it : tree[node])
    {
        if (it != parent)
        {
            // Skip the parent to avoid revisiting
            sum += dfs(it, node, tree, values, k, components); // Add the value of the subtree
        }
    }

    // If the sum is divisible by k, this is a valid component
    if (sum % k == 0)
    {
        ans++;    // Increment the component count
        return 0; // Reset the sum as this part is now separate
    }

    return sum; // Return the sum to propagate to the parent
}

int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
{
    // n nodes from 0 to n-1
    // edges[i] = [ai, bi] : edge between nodes ai and bi in the tree
    // values[i] is the value associated with the ith node, and an integer k
    // valid split of tree: resulting components all have values that are divisible by k
    // value of a connected component is the sum of the values of its nodes.
    // Return the maximum number of components in any valid split
    // Build the tree using an adjacency list
    vector<vector<int>> tree(n);
    for (const auto &edge : edges)
    {
        tree[edge[0]].push_back(edge[1]);
        tree[edge[1]].push_back(edge[0]);
    }

    int ans = 0;                      // Initialize the number of components
    dfs(0, -1, tree, values, k, ans); // Start DFS from node 0
    return ans;                       // Return the total number of components
}

int main()
{
    int n = 5;
    vector<vector<int>> &edges = {{0, 2}, {1, 2}, {1, 3}, {2, 4}};
    vector<int> &values = {1, 8, 1, 4, 4};
    int k = 6;
    cout << "\nmaximum number of components in any valid split are: " << maxKDivisibleComponents(n, edges, values, k);

    return 0;
}