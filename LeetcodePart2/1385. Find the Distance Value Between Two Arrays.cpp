class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=0;
        int n=arr1.size();
        int m=arr2.size();
        for(int i=0;i<n;i++){
            int ele1=arr1[i];
            bool isTrue=true;
            for(int j=0;j<m;j++){
                int ele2=arr2[j];
                if(abs(ele1-ele2)<=d){
                    isTrue=false;
                    break;
                }
            }
            if(isTrue){
                ans++;
            }
        }
        return ans;
    }
};
