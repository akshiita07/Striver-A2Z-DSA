class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });

        int res = 0;
        int a = -1;
        int b = -1;

        for (auto& it : intervals) {
            int l = it[0];
            int r = it[1];

            bool inA = (a >= l && a <= r);
            bool inB = (b >= l && b <= r);

            if (inA && inB) {
                continue;
            }

            if (inA || inB) {
                res++;
                int newNum = r;
                if (inA) {
                    b = a;
                    a = newNum;
                } else {
                    b = newNum;
                }
            } else {
                res += 2;
                a = r - 1;
                b = r;
            }
        }
        return res;
    }
};
