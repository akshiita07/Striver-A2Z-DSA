#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE- TRY ALL SUBARRAYS & TAKE MAXM SUM
int maxSubArray_Brute(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum > max)
            {
                max = sum;
            }
        }
    }
    return max; // maxm sum is
}

// Optimal- USING KADANE'S ALGO--> WHENEVER SUM<0 THEN RESTART FROM SUM=0
int maxSubArray_Optimal(int arr[], int n)
{
    int max = INT_MIN;
    int start=0;
    int end=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum<0){
            sum=0;
            start=i;
        }
        if(sum>max){
            max=sum;
            end=i;
        }
    }
    // start from (start+1) & go till where max sum  was found-(end)
    for(int i=start+1;i<=end;i++){
        cout<<arr[i]<<" ";
    }
    return max;
}

// Optimal- when negative no's
int maxSubArray_Optimal_Leetcode(int arr[], int n)
{
    int maxi = arr[0];
    int sum=arr[0];
    for(int i=1;i<n;i++){
        sum=max(arr[i],sum+arr[i]);
        maxi=max(sum,maxi);
    }
    return maxi;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << "Maxm sum subarray's SUM is: " << maxSubArray_Brute(arr, n);
    // cout << "Maxm sum subarray's SUM is: " << maxSubArray_Optimal(arr, n);
    cout << "Maxm sum subarray's SUM is: " << maxSubArray_Optimal_Leetcode(arr, n);

    return 0;
}