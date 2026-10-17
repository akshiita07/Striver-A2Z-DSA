class Solution {
public:
    int sumDigit(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        // sum of digits in each number
        int n = nums.size();
        vector<pair<int, int>> sumDigitNums; // sumDigit,num
        for (int i = 0; i < n; i++) {
            int sumD = sumDigit(nums[i]);
            sumDigitNums.push_back({sumD, nums[i]});
        }
        // small number first
        sort(sumDigitNums.begin(), sumDigitNums.end());
        // number of swaps reqd

        unordered_map<int, int> hashMap;
        for (int i = 0; i < n; i++) {
            hashMap[nums[i]] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || hashMap[sumDigitNums[i].second] == i) {
                continue;
            }
            int j = i;
            int cycleSize = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = hashMap[sumDigitNums[j].second];
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};
