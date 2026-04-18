class Solution {
public:
    int findReverse(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        int rev = stoi(s);
        cout << "Reverse number is: " << rev << endl;
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            // if present in hashmap then update distance:
            if (hashMap.count(nums[i])) {
                ans = min(ans, i - hashMap[nums[i]]);
            }
            // check reverse:
            int revNumber = findReverse(nums[i]);
            // store rev number->index
            hashMap[revNumber] = i;
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};
