class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int topPtr=x;
        cout<<"Top pointer at: "<<grid[x][y]<<endl;
        int bottomPtr=x+k-1;
        cout<<"Bottom pointer at: "<<grid[x+k-1][y]<<endl;
        while(topPtr<bottomPtr){
            for(int col=y;col<=y+k-1;col++){
                swap(grid[topPtr][col],grid[bottomPtr][col]);
            }
            topPtr++;
            bottomPtr--;
        }
        return grid;
    }
};
