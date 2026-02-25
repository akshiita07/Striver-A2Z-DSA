class Solution {
public:
    string findBinary(int n) {
        string ans = "";
        int i = n;
        int rem;
        while (i > 0) {
            rem = i % 2;
            i = i / 2;
            ans += char('0' + rem);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int findSetBits(int x) {
        string binaryRep = findBinary(x);
        int n = binaryRep.length();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (binaryRep[i] == '1') {
                cnt++;
            }
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int bitsA = findSetBits(a);
            int bitsB = findSetBits(b);

            if (bitsA == bitsB) {
                // if tie then sort by number
                return a < b;
            }
            return bitsA < bitsB; // else sort by set bits
        });

        return arr;
    }
};
