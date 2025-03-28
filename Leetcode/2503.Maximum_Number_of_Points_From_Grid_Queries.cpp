#include <bits/stdc++.h>
using namespace std;

vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
{
    int k = queries.size();
    int m = grid.size();
    int n = grid[0].size();
    vector<int> ans(k, 0);
    // sort queries but remember original order to form ans array:
    vector<pair<int, int>> sortedQueries;
    for (int i = 0; i < k; i++)
    {
        sortedQueries.push_back({queries[i], i});
    }
    sort(sortedQueries.begin(), sortedQueries.end());

    // directions for up,down,left,right:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    // min heap {value,{row,colm}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    // visited matrix:
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    pq.push({grid[0][0], {0, 0}}); //{value,{row,colm}}
    visited[0][0] = true;

    int points = 0;
    for (auto &[query, index] : sortedQueries)
    {
        // the element of top left of grid must be STRICTLY GREATER than query element
        while (!pq.empty() && pq.top().first < query)
        {
            auto [valu, pos] = pq.top();
            pq.pop();
            int row = pos.first;
            int colm = pos.second;
            points++;
            // check neighbours:
            for (int i = 0; i < 4; i++)
            {
                int newRow = row + dx[i];
                int newColm = colm + dy[i];
                if (newRow >= 0 && newRow < m && newColm >= 0 && newColm < n && !visited[newRow][newColm])
                {
                    visited[newRow][newColm] = true;
                    pq.push({grid[newRow][newColm], {newRow, newColm}});
                }
            }
        }
        ans[index] = points;
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 3}, {2, 5, 7}, {3, 5, 1}};
    vector<int> queries = {5, 6, 2};
    vector<int> ans = maxPoints(grid, queries);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}