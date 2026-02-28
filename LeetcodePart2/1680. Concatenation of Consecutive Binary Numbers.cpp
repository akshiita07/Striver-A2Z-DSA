class bruteForce {
public:
    const int MOD = 1e9 + 7;
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
    int convertBinToDec(string bin) { return stoi(bin, nullptr, 2); }
    int concatenatedBinary(int n) {
        string binaryForm = "";
        for (int i = 1; i <= n; i++) {
            binaryForm += findBinary(i);
        }
        cout << "Binary string concatenated: " << binaryForm;
        int decimalForm = convertBinToDec(binaryForm) % MOD;
        return decimalForm;
    }
};
