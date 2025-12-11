class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // n*n city
        // buildings[i] = [x, y]
        // covered building: at least one building in all four directions: left,
        // right, above, and below
        // group by either same x and same y
        unordered_map<int, vector<int>> row, col;

        // Group by x and y
        for (auto& b : buildings) {
            int x = b[0];
            int y = b[1];
            row[x].push_back(y);
            col[y].push_back(x);
        }

        // Sort all groups
        for (auto& r : row) {
            sort(r.second.begin(), r.second.end());
        }
        for (auto& c : col) {
            sort(c.second.begin(), c.second.end());
        }

        int noOfCoveredBuildings = 0;

        for (auto& b : buildings) {
            int x = b[0];
            int y = b[1];

            auto& rowList = row[x];
            auto& colList = col[y];

            int posRow = lower_bound(rowList.begin(), rowList.end(), y) -
                         rowList.begin();
            int posCol = lower_bound(colList.begin(), colList.end(), x) -
                         colList.begin();

            bool hasLeftRight = (posRow > 0 && posRow < rowList.size() - 1);
            bool hasUpDown = (posCol > 0 && posCol < colList.size() - 1);

            if (hasLeftRight && hasUpDown) {
                noOfCoveredBuildings++;
            }
        }
        return noOfCoveredBuildings;
    }
};
