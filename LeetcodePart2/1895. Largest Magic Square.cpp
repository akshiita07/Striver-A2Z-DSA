class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // largest size
        //  sum of row,clm,diagonal same
        //  prefix sums
        vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n, 0));
        // 2 diaginals
        vector<vector<int>> d1(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> d2(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
                d1[i + 1][j + 1] = d1[i][j] + grid[i][j];
                d2[i + 1][j] = d2[i][j + 1] + grid[i][j];
            }
        }

        for (int k = min(m, n); k >= 1; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    int target = row[i][j + k] - row[i][j];
                    bool ok = true;

                    // rows
                    for (int r = i; r < i + k && ok; r++) {
                        if (row[r][j + k] - row[r][j] != target) {
                            ok = false;
                        }
                    }

                    // columns
                    for (int c = j; c < j + k && ok; c++) {
                        if (col[i + k][c] - col[i][c] != target) {
                            ok = false;
                        }
                    }
                    // diagonals
                    if (d1[i + k][j + k] - d1[i][j] != target) {
                        ok = false;
                    }
                    if (d2[i + k][j] - d2[i][j + k] != target) {
                        ok = false;
                    }

                    if (ok) {
                        return k;
                    }
                }
            }
        }
        return 1;
    }
};
