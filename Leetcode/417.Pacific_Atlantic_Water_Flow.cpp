#include <bits/stdc++.h>
using namespace std;

// O((m × n)²)
bool dfs_brute_force(vector<vector<int>> &heights, int i, int j, vector<vector<int>> &visited, bool isPacific)
{
    int m = heights.size();
    int n = heights[0].size();
    // Pacific Ocean: left & top edges
    if (isPacific)
    {
        if (i == 0 || j == 0)
        {
            return true;
        }
    }
    // Atlantic Ocean: right & bottom edges
    if (!isPacific)
    {
        if (i == m - 1 || j == n - 1)
        {
            return true;
        }
    }
    visited[i][j] = 1;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // N,S,E,W
    for (auto &it : directions)
    {
        int new_i = i + it[0];
        int new_j = j + it[1];
        if (new_i < 0 || new_j < 0 || new_i >= m || new_j >= n)
        {
            continue;
        }
        if (visited[new_i][new_j])
        {
            continue;
        }
        if (heights[new_i][new_j] > heights[i][j])
        {
            continue;
        }
        if (dfs_brute_force(heights, new_i, new_j, visited, isPacific))
        {
            return true;
        }
    }
    return false;
}

vector<vector<int>> brute_force(vector<vector<int>> &heights)
{
    int m = heights.size();
    int n = heights[0].size();
    // Pacific Ocean: left & top edges
    // Atlantic Ocean: right & bottom edges
    // heights[r][c]: height above sea level of the cell at coordinate (r, c)
    // if neightbouring cell height <= current cell height then water can flow to neighboring cells
    // return result[i] = [ri, ci] : rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans
    if (m == 1 && n == 1)
    {
        // only 1 cell so can flow:
        return {{0, 0}};
    }
    // run 2 DFS per cell to check if they can flow to both Pacific and Atlantic ocean:
    vector<vector<int>> ans;
    // for each cell:
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 2 visited arrays for both oceans:
            vector<vector<int>> pacificVis(m, vector<int>(n, 0));
            vector<vector<int>> atlanticVis(m, vector<int>(n, 0));
            // send flag to mark whether going to pacific (true) or atlantic (false) ocean:
            bool canFlowToPacific = dfs_brute_force(heights, i, j, pacificVis, true);
            bool canFlowToAtlantic = dfs_brute_force(heights, i, j, atlanticVis, false);
            if (canFlowToPacific && canFlowToAtlantic)
            {
                ans.push_back({i, j});
            }
        }
    }
    return ans;
}

// optimise:

bool dfs(vector<vector<int>> &heights, int i, int j, vector<vector<int>> &visited)
{
    int m = heights.size();
    int n = heights[0].size();
    visited[i][j] = 1;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // N,S,E,W
    for (auto &it : directions)
    {
        int new_i = i + it[0];
        int new_j = j + it[1];
        if (new_i < 0 || new_j < 0 || new_i >= m || new_j >= n)
        {
            continue;
        }
        if (visited[new_i][new_j])
        {
            continue;
        }
        if (heights[new_i][new_j] < heights[i][j])
        {
            continue;
        }
        if (dfs(heights, new_i, new_j, visited))
        {
            return true;
        }
    }
    return false;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int m = heights.size();
    int n = heights[0].size();
    // Pacific Ocean: left & top edges
    // Atlantic Ocean: right & bottom edges
    // heights[r][c]: height above sea level of the cell at coordinate (r, c)
    // if neightbouring cell height <= current cell height then water can flow to neighboring cells
    // return result[i] = [ri, ci] : rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans
    if (m == 1 && n == 1)
    {
        // only 1 cell so can flow:
        return {{0, 0}};
    }
    // check in reverse order: can water flow from ocean to cell:
    vector<vector<int>> ans;
    // 2 visited arrays for both oceans:
    vector<vector<int>> pacificVis(m, vector<int>(n, 0));
    vector<vector<int>> atlanticVis(m, vector<int>(n, 0));
    // pacific edges:
    for (int i = 0; i < m; i++)
    {
        dfs(heights, i, 0, pacificVis);
    }
    for (int j = 0; j < n; j++)
    {
        dfs(heights, 0, j, pacificVis);
    }
    // atlantic edges:
    for (int i = 0; i < m; i++)
    {
        dfs(heights, i, n - 1, atlanticVis);
    }
    for (int j = 0; j < n; j++)
    {
        dfs(heights, m - 1, j, atlanticVis);
    }
    // intersections:
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (pacificVis[i][j] && atlanticVis[i][j])
            {
                ans.push_back({i, j});
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}