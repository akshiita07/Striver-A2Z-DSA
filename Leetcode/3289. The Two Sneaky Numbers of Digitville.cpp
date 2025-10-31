class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> hashMap;
        for(int i=0;i<nums.size();i++){
            hashMap[nums[i]]++;
        }
        for(auto it:hashMap){
            if(it.second==2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
