#include <bits/stdc++.h>
using namespace std;

// brute force:         TIME:O(n^2)
int findAllSubarraysWithGivenSum_brute(int arr[], int target, int n)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (sum == target)
            {
                count++;
            }
        }
    }

    return count;
}

// OPTIMAL: PREFIX SUM         TIME:O(n* 1)for unordered map else O(n*logn)         TIME:O(n)-> unordered map
int findAllSubarraysWithGivenSum_optimal(int arr[], int target, int n)
{
    int sum = 0;
    int count = 0;
    unordered_map<int, int> prefixSum; // sum,COUNT
    // store a 0 index in map
    prefixSum[0]=1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        int rem = sum - target;
        count+=prefixSum[rem];
        prefixSum[sum]+=1;
    }
    return count;
}

int main()
{
    int arr[] = {3, 1, 2, 4};
    int target = 6;
    int n = sizeof(arr) / sizeof(arr[0]);

    // cout<<"No of subarrays in arr with sum= "<<target<<" are: "<<findAllSubarraysWithGivenSum_brute(arr,target,n);
    cout << "No of subarrays in arr with sum= " << target << " are: " << findAllSubarraysWithGivenSum_optimal(arr, target, n);

    return 0;
}