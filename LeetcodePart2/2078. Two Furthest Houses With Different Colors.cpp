class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int ans=INT_MIN;
        //from left:
        for(int i=0;i<n;i++){
            if(colors[i]!=colors[n-1]){
                ans=max(ans,abs(i-(n-1)));
                break;
            }
        }
        //from right:
        for(int i=n-1;i>=0;i--){
            if(colors[i]!=colors[0]){
                ans=max(ans,abs(i));
                break;
            }
        }
        return ans;
    }
};
