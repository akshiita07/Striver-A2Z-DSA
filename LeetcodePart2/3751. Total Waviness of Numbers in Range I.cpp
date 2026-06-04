class Solution {
public:
    vector<int> findCountDigits(int num) {
        vector<int> ans;
        while (num > 0) {
            int digit = num % 10;
            ans.push_back(digit);
            num = num / 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int totalWaviness(int num1, int num2) {
        // peak digit: num>neighbors
        // valley digit: num<neighbors
        // waviness of number=peak+valleys
        // if number digits<3-> wavniess=0
        // return-> sum of wavniness for all nums
        int ans = 0;
        for (int i = num1; i <= num2; i++) {
            vector<int> digits = findCountDigits(i);
            int noOfDigits = digits.size();
            cout << "Found digits= " << noOfDigits << endl;
            if (noOfDigits >= 3) {
                for (int j = 1; j < noOfDigits - 1; j++) {
                    if (((digits[j] > digits[j - 1]) &&
                         (digits[j] > digits[j + 1])) ||
                        ((digits[j] < digits[j - 1]) &&
                         (digits[j] < digits[j + 1]))) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
