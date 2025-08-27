#include <bits/stdc++.h>
using namespace std;

struct State
{
    int r, c, dir, turn, expect;
};

int lenOfVDiagonal(vector<vector<int>> &grid)
{

    int n = grid.size();
    int m = grid[0].size();
    // each element is either 0, 1, or 2

    // 4 diagonal directions:
    vector<pair<int, int>> dirs = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    // clockwise turn
    vector<int> cw = {1, 2, 3, 0};

    // memo[r][c][dir][turn][expect] = best length
    static int memo[505][505][4][2][3];
    memset(memo, -1, sizeof(memo));

    function<int(int, int, int, int, int)> dfs = [&](int r, int c, int dir, int turn, int expect)
    {
        if (r < 0 || r >= n || c < 0 || c >= m)
        {
            return 0;
        }
        if (grid[r][c] != expect)
        {
            return 0;
        }

        int &res = memo[r][c][dir][turn][expect];
        if (res != -1)
        {
            return res;
        }

        int nextExpect;
        if (expect == 1)
        {
            nextExpect = 2;
        }
        else if (expect == 2)
        {
            nextExpect = 0;
        }
        else
        {
            nextExpect = 2;
        }

        int ans = 1;
        // continue straight
        ans = max(ans, 1 + dfs(r + dirs[dir].first, c + dirs[dir].second, dir, turn, nextExpect));

        // if not turned yet, try turning clockwise
        if (turn == 0)
        {
            int ndir = cw[dir];
            ans = max(ans, 1 + dfs(r + dirs[ndir].first, c + dirs[ndir].second, ndir, 1, nextExpect));
        }
        return res = ans;
    };

    int best = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                for (int d = 0; d < 4; d++)
                {
                    best = max(best, dfs(i, j, d, 0, 1));
                }
            }
        }
    }
    return best;
}

int main()
{
    vector<vector<int>> grid = {};
    cout << "\nLength of longest V-shaped diagonal segment= " << lenOfVDiagonal(grid);
    return 0;
}