class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // get actual sorted order of heights:
        vector<int> actualOrder=heights;
        sort(actualOrder.begin(),actualOrder.end());
        // compare which indices r wrong
        int count=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]==actualOrder[i]){
                // correct index
                continue;
            }else{
                count++;
            }
        }
        return count;
    }
};