class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        // even add
        // odd subtract
        // get max alt score
        vector<int> squaresArr;
        for(int i=0;i<n;i++){
            long long sq=1LL*nums[i]*nums[i];
            squaresArr.push_back(sq);
        }
        n=squaresArr.size();
        long long ans=0;
        sort(squaresArr.begin(),squaresArr.end());
        for(int i=0;i<n;i++){
            if(i<n/2){
                ans-=squaresArr[i];
            }else{
                ans+=squaresArr[i];
            }
        }
        return ans;
    }
};
