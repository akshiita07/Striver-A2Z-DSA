#include <bits/stdc++.h>
using namespace std;

int maximumInvitations(vector<int> &favorite)
{
    // favorite[i] denotes the favorite person of the ith employee
    int n = favorite.size();
    // sit next to favourite person at circular table
    // return the maximum number of employees that can be invited to the meeting

    // 1. store indegree of each node:
    vector<int> indegree(n, 0);
    // 2. adjacency list:
    vector<vector<int>> adjacency(n);
    // 3. visited array:
    vector<int> visited(n, 0); // initilly 0

    // 4. compute indegree
    // 5. create adjacency list:
    for (int i = 0; i < n; i++)
    {
        indegree[favorite[i]]++;
        adjacency[favorite[i]].push_back(i); // 3 employee ke fvourites={_,_,_}
    }

    // 6. queue for traversal:
    queue<int> qu;
    // 7. take max depth:
    vector<int> depth(n, 1);

    // 8. find nodes with indegree=0 ie employees jo kisi ke favourite nahi hai..add them to queue
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            qu.push(i);
        }
    }

    // 9. topological sorting to find chain of max depth:
    while (!qu.empty())
    {
        int node = qu.front();
        qu.pop();
        visited[node] = 1;

        int fav = favorite[node];
        depth[fav] = max(depth[fav], depth[node] + 1);
        indegree[fav]--;
        if (indegree[fav] == 0)
        {
            qu.push(fav);
        }
    }

    int maxCycleSize = 0;
    int maxTwoChains = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            int size = 0;
            int curr = i;

            while (visited[curr] == 0)
            {
                visited[curr] = 1;
                size++;
                curr = favorite[curr];
            }

            if (size == 2)
            {
                maxTwoChains += depth[i] + depth[favorite[i]];
            }
            else
            {
                maxCycleSize = max(maxCycleSize, size);
            }
        }
    }
    return max(maxTwoChains, maxCycleSize);
}

int main()
{
    vector<int> favorite = {3, 0, 1, 4, 1};
    cout << "\nMaximum no of employees that can be invited to the meeting= " << maximumInvitations(favorite);

    return 0;
}