class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n1=landStartTime.size();
        int n2=waterStartTime.size();
        int ans=INT_MAX;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                //land->water:
                int landFinish=landStartTime[i]+landDuration[i];
                int waterStart=max(landFinish,waterStartTime[j]);
                ans=min(ans,waterStart+waterDuration[j]);
                // water->land:
                int waterFinish=waterStartTime[j]+waterDuration[j];
                int landStart=max(waterFinish,landStartTime[i]);
                ans=min(ans,landStart+landDuration[i]);
            }
        }
        return ans;
    }
};
