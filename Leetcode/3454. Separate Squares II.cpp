class SegTree {
    vector<int> cover, len, xs;
    int n;

    void upd(int ql, int qr, int v, int l, int r, int i) {
        if (xs[r + 1] <= ql || xs[l] >= qr)
            return;

        if (ql <= xs[l] && xs[r + 1] <= qr) {
            cover[i] += v;
        } else {
            int m = (l + r) / 2;
            upd(ql, qr, v, l, m, i * 2 + 1);
            upd(ql, qr, v, m + 1, r, i * 2 + 2);
        }

        if (cover[i] > 0) {
            len[i] = xs[r + 1] - xs[l];
        } else if (l == r) {
            len[i] = 0;
        } else {
            len[i] = len[i * 2 + 1] + len[i * 2 + 2];
        }
    }

public:
    SegTree(vector<int>& x) : xs(x) {
        n = xs.size() - 1;
        cover.assign(4 * n, 0);
        len.assign(4 * n, 0);
    }

    void update(int l, int r, int v) { upd(l, r, v, 0, n - 1, 0); }

    int query() { return len[0]; }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int, int, int, int>> ev;
        set<int> xsSet;

        for (auto& s : squares) {
            int x = s[0], y = s[1], l = s[2];
            ev.emplace_back(y, 1, x, x + l);
            ev.emplace_back(y + l, -1, x, x + l);
            xsSet.insert(x);
            xsSet.insert(x + l);
        }

        sort(ev.begin(), ev.end());
        vector<int> xs(xsSet.begin(), xsSet.end());
        SegTree st(xs);

        vector<double> pref;
        vector<int> widths;
        double area = 0;
        int prevY = get<0>(ev[0]);

        for (auto& [y, d, xl, xr] : ev) {
            area += 1LL * st.query() * (y - prevY);
            st.update(xl, xr, d);
            pref.push_back(area);
            widths.push_back(st.query());
            prevY = y;
        }

        double half = area / 2.0;
        int i = lower_bound(pref.begin(), pref.end(), half) - pref.begin() - 1;

        double used = pref[i];
        int w = widths[i];
        int y = get<0>(ev[i]);

        return y + (half - used) / w;
    }
};
