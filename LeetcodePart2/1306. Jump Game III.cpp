class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // queue:
        queue<int> qu;
        int n=arr.size();
        vector<bool> visitedArr(n,false);
        // add start node in queue and make it visited:
        qu.push(start);
        visitedArr[start]=true;
        while(!qu.empty()){
            int index=qu.front();
            //remove it:
            qu.pop();
            //check if value is 0:
            if(arr[index]==0){
                return true;
            }
            int fwd=index+arr[index];
            int backwd=index-arr[index];
            // check if in bounds:
            if(fwd<n && visitedArr[fwd]==false){
                qu.push(fwd);
                visitedArr[fwd]=true;
            }
            if(backwd>=0 && visitedArr[backwd]==false){
                qu.push(backwd);
                visitedArr[backwd]=true;
            }
        }
        return false;
    }
};
