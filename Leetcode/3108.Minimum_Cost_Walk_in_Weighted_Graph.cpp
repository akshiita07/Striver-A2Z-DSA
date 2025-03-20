#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> parent, rank;

    // constructor:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            // Initialize parent[i] = i
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {

            if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else
            {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
        }
    }
};
class Solution
{
public:
    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
    {
        // edges[i] = [ui, vi, wi]: edge between vertices ui and vi with a weight of wi
        // cost of a walk starting at node u and ending at node v =bitwise AND of the weights of the edges traversed during the walk
        // For each query: find the minimum cost of the walk starting at vertex si and ending at vertex ti else the answer is -1
        // return : answer[i] denotes the minimum cost of a walk for query i

        // if NO edge between query[s,t] then ans=-1

        // disjoint set union:dsu
        DSU dsu(n);
        unordered_map<int, int> minCost; // id->min&cost
        // group nodes using union find:
        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            dsu.unite(u, v);
        }

        unordered_map<int, int> minAnd;
        for (auto &it : edges)
        {
            int root = dsu.find(it[0]);
            if (minAnd.find(root) == minAnd.end())
            {
                // not found:
                minAnd[root] = it[2];
            }
            else
            {
                // found then perform AND:
                minAnd[root] &= it[2];
            }
        }

        vector<int> ans;
        for (auto &it : query)
        {
            int s = it[0];
            int t = it[1];
            if (dsu.find(s) != dsu.find(t))
            {
                // no connecting edge so return -1
                ans.push_back(-1);
            }
            else
            {
                // found:
                ans.push_back(minAnd[dsu.find(s)]);
            }
        }
        return ans;
    }
};

int main()
{
    int n = 5;
    vector<vector<int>> edges = {{0, 1, 7}, {1, 3, 7}, {1, 2, 1}};
    vector<vector<int>> query = {{0, 3}, {3, 4}};
    vector<int> ans = minimumCost(n, edges, query);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}