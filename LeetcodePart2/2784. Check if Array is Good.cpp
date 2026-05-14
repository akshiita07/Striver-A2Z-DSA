class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
        if (n != maxEle + 1) {
            // length of array check:
            return false;
        }
        // check contents:
        // base[maxEle] must contain elements 1,2,_,n-1,n,n ie all elements 1 time but nth element 2 times
        unordered_map<int, int> hashMap;
        for (int i = 0; i < n; i++) {
            hashMap[nums[i]]++;
        }
        bool isGood = false;
        for (auto it : hashMap) {
            // maxEle must be repeated 2 times while rest only 1
            if ((it.first == maxEle && it.second == 2) ||
                (it.first != maxEle && it.second == 1)) {
                isGood = true;
            } else {
                isGood = false;
                break;
            }
        }
        if (isGood == true) {
            return true;
        }
        return false;
    }
};
