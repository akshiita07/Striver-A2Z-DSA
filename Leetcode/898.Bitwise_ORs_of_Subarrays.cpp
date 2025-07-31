#include <bits/stdc++.h>
using namespace std;

int brute_force(vector<int> &arr)
{
    // return the number of distinct bitwise ORs of all the non-empty subarrays of arr
    // generate all subarrays:
    int n = arr.size();
    // find bitwise OR of each subarray
    // store all these in a set
    set<int> distinctOR;
    for(int i=0;i<n;i++){
        int currOR=0;
        for(int j=i;j<n;j++){
            currOR = currOR | arr[j];
            distinctOR.insert(currOR);
        }
    }
    // return the size of the set
    return distinctOR.size();
}

int subarrayBitwiseORs(vector<int> &arr)
{
    // return the number of distinct bitwise ORs of all the non-empty subarrays of arr
    int n = arr.size();
    unordered_set<int> ans;
    unordered_set<int> prev;
    for(auto it:arr){
        unordered_set<int> curr;
        curr.insert(it);
        for(auto prev_it:prev){
            //take OR
            curr.insert(prev_it | it);
        }
        prev=curr;
        ans.insert(prev.begin(), prev.end());
    }
    return ans.size();
}

int main()
{
    vector<int> arr = {1,1,2};
    cout << "\nAns using brute_force: " << brute_force(arr);
    cout << "\nAns: " << subarrayBitwiseORs(arr);
    return 0;
}
