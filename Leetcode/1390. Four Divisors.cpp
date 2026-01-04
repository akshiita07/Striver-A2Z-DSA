class Solution {
public:
    vector<int> count_divisors(int n) {
        vector<int> ans;
        // check all divisors from 1 to number itself
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                ans.push_back(i);
                // for second divisor: no/i:
                if ((n / i) != i) {
                    // do not add same divisor twice
                    ans.push_back(n / i);
                }
            }
        }
        cout << "\nAll divisiors of number " << n << " are: ";
        for (auto it : ans) {
            cout << it << " ";
        }
        return ans;
    }

    int sumFourDivisors(vector<int>& nums) {
        int noOfDivisors = 0;
        int sum = 0;
        // find out how many divisors does each no has:
        for (auto it : nums) {
            vector<int> divisors = count_divisors(it);
            noOfDivisors = divisors.size();
            if (noOfDivisors == 4) {
                // exactly 4 divisors so add them up & return ans;
                for (auto ele : divisors) {
                    sum += ele;
                }
            }
        }
        // If there is no such integer in the array, return 0
        return sum;
    }
};
