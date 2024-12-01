class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // pehle duplicate then number
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(arr[i]==2*arr[j]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};