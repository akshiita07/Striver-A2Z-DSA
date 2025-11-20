class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const auto& a, const auto& b) {
                 if (a[1] != b[1])
                     return a[1] < b[1];
                 return a[0] > b[0];
             });

        int res = 0;
        int s1 = -1e9;
        int s2 = -1e9; 

        for (auto& it : intervals) {
            int l = it[0];
            int r = it[1];
            if (s1 >= l && s2 >= l) {
                continue;
            } else if (s2 < l) {
                res += 2;
                s1 = r - 1;
                s2 = r;
            } else {
                res += 1;
                s1 = s2;
                s2 = r;
            }
        }
        return res;
    }
};
