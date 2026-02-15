class Solution {
public:
    string addBinary(string a, string b) {
        // start from end

        if (a == "0" && b == "0") {
            return "0";
        }
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = 0;
            sum += carry;
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            carry = sum / 2; // if sum=2 then carry=1
            ans += ((sum % 2) + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
