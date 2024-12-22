#include <bits/stdc++.h>
using namespace std;

vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
{
    //  heights[i] represents the height of the ith building
    // person in building i can move to building j only if i<j and heights[i] < heights[j]
    // queries[i] = [ai, bi]
    // in ith query:  Alice in building ai while Bob in building bi
    // return array ans[i]: index of leftmost building where Alice and Bob can meet on ith query
    int n = heights.size();
    int q = queries.size();
    vector<int> ans(q, -1);
    vector<vector<pair<int, int>>> deferred(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (int i = 0; i < q; i++)
    {
        int a = queries[i][0];
        int b = queries[i][1];
        if (a > b)
        {
            swap(a, b);
        }
        if (a == b || heights[a] < heights[b])
        {
            ans[i] = b;
        }
        else
        {
            // Store height of Alice's building and query index.
            deferred[b].emplace_back(heights[a], i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (auto &query : deferred[i])
        {
            pq.push(query);
        }
        while (!pq.empty() && pq.top().first < heights[i])
        {
            ans[pq.top().second] = i;
            pq.pop();
        }
    }

    return ans;
}

int main()
{
    vector<int> heights = {6, 4, 8, 5, 2, 7};
    vector<vector<int>> queries = {{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}};
    // Output: [2,5,-1,5,2]
    vector<int> ans = leftmostBuildingQueries(heights, queries);
    cout << "Ans:\n";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}