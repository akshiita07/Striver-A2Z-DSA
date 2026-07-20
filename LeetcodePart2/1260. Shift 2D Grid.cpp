class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k %= total;
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int oldIdx=i*n+j;
                int newIdx=(oldIdx+k)%total;
                int newRow=newIdx/n;
                int newCol=newIdx%n;
                ans[newRow][newCol]=grid[i][j];
            }
        }
        return ans;
    }
};
