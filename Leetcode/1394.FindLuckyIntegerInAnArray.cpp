class Solution {
public:
    int findLucky(vector<int>& arr) {
        // lucky intger frequency==value
        unordered_map<int,int> mpp;
        int maxLargest=-1;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        for(auto it:mpp){
            if(it.second==it.first){
                maxLargest=max(it.first,maxLargest);
            }
        }
        return maxLargest;
    }
};