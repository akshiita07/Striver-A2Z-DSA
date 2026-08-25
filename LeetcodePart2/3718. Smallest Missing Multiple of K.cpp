class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> hashSet;
        for (auto it : nums) {
            hashSet.insert(it);
        }
        //go thru multiples of k & find missing one in hashSett:
        for(int i=k;;i+=k){
            if(!hashSet.contains(i)){
                return i;
            }
        }
        return 0;
    }
};
