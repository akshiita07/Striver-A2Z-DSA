class Solution {
public:
    int brute_force(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    return nums1[i];
                }
            }
        }
        return -1;//else
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        set<int> set1;
        for(auto it:nums1){
            set1.insert(it);
        }
        for(int i=0;i<n2;i++){
            if(set1.contains(nums2[i])){
                return nums2[i];
            }
        }
        return -1;//else
    }
};
