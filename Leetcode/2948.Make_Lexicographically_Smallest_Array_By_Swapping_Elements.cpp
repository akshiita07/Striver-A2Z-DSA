#include <bits/stdc++.h>
using namespace std;

// DSU (also known as Union-Find) is a data structure used to group elements into sets based on connectivity.
// 2 operations:
// Find(x) → Determines which set element x belongs to.
// Union(x, y) → Merges the sets containing x and y.
class DSU
{
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            // each element is its own parent
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
            if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

vector<int>
lexicographicallySmallestArray(vector<int> &nums, int limit)
{
    // swap nums[i] & nums[j] if |nums[i] - nums[j]| <= limit
    // Return the lexicographically smallest array possible

    // treat each index as a node & draw edge if |nums[i] - nums[j]| <= limit:
    // use DSU(disjoint set union) to group indices that can be swapped
    int n = nums.size();
    DSU dsu(n);
    vector<pair<int, int>> sortedNums;
    for (int i = 0; i < n; i++)
    {
        sortedNums.push_back({nums[i], i}); // {element,index}
    }
    sort(sortedNums.begin(), sortedNums.end());
    // check if satisfy cnd:
    for (int i = 1; i < n; i++)
    {
        if ((sortedNums[i].first - sortedNums[i - 1].first) <= limit)
        {
            dsu.unite(sortedNums[i].second, sortedNums[i - 1].second);
        }
    }

    unordered_map<int, vector<int>> component;
    unordered_map<int, vector<int>> componentValues;

    for (int i = 0; i < n; i++)
    {
        int root = dsu.find(i);
        component[root].push_back(i);
        componentValues[root].push_back(nums[i]);
    }

    for (auto &[root, values] : componentValues)
    {
        sort(values.begin(), values.end());
    }

    vector<int> ans(n);
    for (auto &[root, indices] : component)
    {
        sort(indices.begin(), indices.end());
        vector<int> &values = componentValues[root];
        for (int i = 0; i < indices.size(); i++)
        {
            ans[indices[i]] = values[i];
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 5, 3, 9, 8};
    int limit = 2;
    cout << "Ans:\n";
    vector<int> ans = lexicographicallySmallestArray(nums, limit);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}