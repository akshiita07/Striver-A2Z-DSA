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

    int findSetBits(string binaryRep) {
        int n = binaryRep.length();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (binaryRep[i] == '1') {
                cnt++;
            }
        }
        return cnt;
    }

    bool isPrime(int n) {
        int cnt = 0;
        if (n <= 1) {
            return false;
        } else {
            for (int i = 1; i <= n; i++) {
                if (n % i == 0) {
                    cnt++;
                }
            }
            if (cnt > 2) {
                return false;
            } else {
                return true;
            }
        }
        return false;
    }

    int countPrimeSetBits(int left, int right) {
        // start from left and end at right:
        int ans = 0;
        for (int i = left; i <= right; i++) {
            // for number write binary representation:
            string binaryRep = findBinary(i);
            // check no of set bits:
            int cnt = findSetBits(binaryRep);
            // check if this no is prime
            if (isPrime(cnt)) {
                ans++;
            }
        }
        return ans;
    }
};
