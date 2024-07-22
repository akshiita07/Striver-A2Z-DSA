#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: TIME:O(n^2)        SPACE:O(1)
int maxProduct_brute(vector<int> &nums)
{
    int maxPro = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        int product = 1;
        for (int j = i; j < n; j++)
        {
            product *= nums[j];
            maxPro = max(maxPro, product);
        }
    }

    return maxPro;
}

// OPTIMAL: TIME:O()        SPACE:O(1)
int maxProduct_optimal(vector<int> &nums)
{
    int maxPro = INT_MIN;
    int n = nums.size();
    int prefixProduct=1;
    int suffixProduct=1;
    for(int i=0;i<n;i++){
        if(prefixProduct==0){
            prefixProduct=1;
        }
        if(suffixProduct==0){
            suffixProduct=1;
        }
        prefixProduct*=nums[i];     //from start    
        suffixProduct*=nums[n-i-1];     //from end

        maxPro=max(maxPro,max(prefixProduct,suffixProduct));
    }

    return maxPro;
}

int main()
{
    vector<int> nums = {2, 3, -2, 4};
    // cout << "\nThe max product from subarray is: " << maxProduct_brute(nums) << endl;
    cout << "\nThe max product from subarray is: " << maxProduct_optimal(nums) << endl;

    return 0;
}