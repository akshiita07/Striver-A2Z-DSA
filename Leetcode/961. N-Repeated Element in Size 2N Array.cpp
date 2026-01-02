class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int len=nums.size();
        int n=(len)/2;
        unordered_map<int,int> count;
        for(int i=0;i<len;i++){
            count[nums[i]]++;
        }
        for(auto it:count){
            if(it.second==n){
                return it.first;
            }
        }
        return 0;
    }
};
