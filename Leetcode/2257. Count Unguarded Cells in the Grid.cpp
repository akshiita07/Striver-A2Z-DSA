class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        // mxn grid
        // guards[i] = [rowi, coli]  positions of the ith guard
        // walls[j] = [rowj, colj] positions of jth wall
        // guard can see every cell in the four cardinal directions unless
        // obstructed by a wall or another guard. A cell is guarded if there is
        // at least one guard that can see it. Return the number of unoccupied
        // cells that are NOT guarded.
        vector<vector<int>> createGrid(m, vector<int>(n, 0));
        // 0: unoccupied, 1: guard, 2: wall, 3: guarded
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // North, South, West, East

        // Mark guards and walls on the grid
        for (auto& it : guards) {
            createGrid[it[0]][it[1]] = 1; // Guard specified by 1
        }
        for (auto& it : walls) {
            createGrid[it[0]][it[1]] = 2; // Wall specified by 2
        }

        // Simulate visibility for guards
        for (auto& it : guards) {
            int x = it[0];
            int y = it[1];
            for (auto& [dx, dy] : directions) {
                // next cell:
                int nx = x + dx;
                int ny = y + dy;
                while (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                       createGrid[nx][ny] != 1 &&
                       createGrid[nx][ny] !=
                           2) // within coordinates & not a guard or wall then
                              // under visiblility
                {
                    if (createGrid[nx][ny] == 0) {
                        createGrid[nx][ny] =
                            3; // Mark as guarded as specifed  by 3
                    }
                    nx += dx;
                    ny += dy;
                }
            }
        }

        // Count unguarded cells
        int unguardedCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (createGrid[i][j] == 0)
                    unguardedCount++; // Unoccupied and unguarded
            }
        }

        return unguardedCount;
    }
};
