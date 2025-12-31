class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();
        int lo = 1, hi = n, ans = 0;

        vector<int> dir = {0, 1, 0, -1, 0};

        auto canCross = [&](int day) {
            vector<vector<int>> grid(row, vector<int>(col, 0));
            for (int i = 0; i < day; i++) {
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }

            queue<pair<int,int>> q;
            vector<vector<int>> vis(row, vector<int>(col, 0));

            for (int j = 0; j < col; j++) {
                if (grid[0][j] == 0) {
                    q.push({0, j});
                    vis[0][j] = 1;
                }
            }

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                if (r == row - 1) return true;

                for (int k = 0; k < 4; k++) {
                    int nr = r + dir[k];
                    int nc = c + dir[k + 1];
                    if (nr >= 0 && nc >= 0 && nr < row && nc < col &&
                        !vis[nr][nc] && grid[nr][nc] == 0) {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            return false;
        };

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canCross(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};
