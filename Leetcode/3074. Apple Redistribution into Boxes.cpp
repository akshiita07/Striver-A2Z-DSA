#include <bits/stdc++.h>
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        //sort capacity in big to small
        sort(capacity.begin(),capacity.end(),greater<int>());
        int countOfApples=0;
        countOfApples=accumulate(apple.begin(),apple.end(),0);
        int ans=0;
        int capac=0;
        for(int i=0;i<m;i++){
            capac+=capacity[i];
            ans++;
            if(capac>=countOfApples){
                break;
            }
        }
        return ans;
    }
};
