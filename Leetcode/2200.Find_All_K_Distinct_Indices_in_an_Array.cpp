#include<bits/stdc+t.h›
using namespace std;

vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        // k-distant index: index i of nums for which there exists at least one
        // index j such that |i - j| <= k and nums[j] == key
        // return sorted list of all k-distant indices
        int n = nums.size();
        vector<int> ans;
        // 1. find at which index u find key in nums array
        vector<int> values_of_j;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                values_of_j.push_back(i);
            }
        }
        // debugging:
        cout<<"j values:\n";
        for(auto it:values_of_j){
            cout<<it<<" ";
        }
        // 2. iterate to check if 2nd consition is satisfied with either value
        // of j:
        for (int p=0; p < values_of_j.size(); p++) {
            int j=values_of_j[p];
            for (int i = 0; i < n; i++) {
                if (abs(i - j) <= k) {
                    ans.push_back(i);
                }
            }
        }
        // 3. remove duplicates from ans:
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }

int main(){
  vector‹int > nums={3,4,9,1,3,9,5};
  int key=9; int k=1;
  vector<int> ans=findKDistantIndices (nums,key,k);
  cout<<"Ans\n";
  for(auto it:ans) {
    cout<<it<<"";
  }
}
