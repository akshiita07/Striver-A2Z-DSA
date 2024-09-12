class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> hashMap;
        for(auto it:nums){
            hashMap[it]++;
        }
        int sum=0;
        for(auto it:hashMap){
            if(it.second==1){
                sum+=it.first;
            }
        }
        return sum;
    }
};