class bruteForceSolution {
public:
    long long convertToDecimal(string s) {
        // long long dec = stoi(s, nullptr, 2);
        // return dec;
        long long dec = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            dec = (long long)dec * 2 + (s[i] - '0');
        }
        return dec;
    }

    int numSteps(string s) {
        // reduce number s to 1
        int n = s.length();
        // even no- /2
        // off no- +1
        long long num = convertToDecimal(s);
        int step = 0;
        while (num != 1) {
            if (num % 2 == 0) {
                num = num / 2;
            } else {
                num += 1;
            }
            step++;
        }
        return step;
    }
};
class Solution {
public:
    int numSteps(string s) {
        // reduce number s to 1
        int n = s.length();
        // even no- /2
        // off no- +1
        int step = 0;
        while (s != "1") {
            if (s.back() == '0') {
                // even so /2:
                s.pop_back();
            } else {
                // odd so +1:
                // binary addition:
                int i = s.length() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i < 0) {
                    // carry
                    s = '1' + s;
                } else {
                    s[i] = '1';
                }
            }
            step++;
        }
        return step;
    }
};
