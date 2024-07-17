#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE- LOOP TO FIND SUM=sumSubarr & RETURN LARGEST SUBARRAY SIZE
int lenOfLongSubarr_BruteForce(int arr[], int n, int sumSubarr)
{
    // TIME- O(n^3)     EXTRA SPACE-O(1)
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "\nNow starting from " << arr[i];
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            cout << "\nSum is: " << sum;

            if (sum == sumSubarr)
            {
                cout << "\nFound sum= " << sumSubarr;
                if (length < (j - i + 1))
                {
                    length = (j - i + 1);
                }
            }
        }
    }

    return length;
}

// BRUTE2- REMOVE k LOOP
int lenOfLongSubarr_Brute2(int arr[], int n, int k)
{
    // TIME- O(n^2)     EXTRA SPACE-O(1)
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        cout << "\nNow starting from " << arr[i];
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            cout << "\nSum is: " << sum;

            if (sum == k)
            {
                cout << "\nFound sum= " << k;
                if (length < (j - i + 1))
                {
                    length = (j - i + 1);
                }
            }
        }
    }

    return length;
}

// BETTER- USE HASHING TO STORE PREFIX SUM--> WORKS FOR +,-,0s
int lenOfLongSubarr_Better(int arr[], int n, int k)
{
    // TIME- O(nlogn)-ordered map       O(n*1)-unordered map     EXTRA SPACE-O(n)->hash map to store prefix sum
    map<int, int> prefixSum;            // prefix sums as keys and their corresponding indices as values
    int length = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            length = max(length, i + 1);
        }

        int rem = sum - k;

        // if this remainder is found in hash map
        if (prefixSum.find(rem) != prefixSum.end())
        {
            length = max(length, i - prefixSum[rem]);
        }

        // if prev exists then update
        if (prefixSum.find(sum) == prefixSum.end())
        {
            prefixSum[sum] = i;
        }
    }

    return length;
}

// Optimal- WORKS FOR +,0s              NOT FOR NEGATIVES!!
int lenOfLongSubarr_Optimal(int arr[], int n, int k)
{
    int length = 0;
    int i = 0;
    int j = 0;
    int sum = 0;
    while (j < n)
    {
        sum += arr[j];
        while (sum > k && i<=j)
        {
            sum -= arr[i];
            // trim from left
            i++;
        }
        if (sum == k)
        {
            length = max(length, (j - i + 1));
        }
        j++;
    }

    return length;
}

// leetcode- return how many such subarrays r possible
int subarraySum(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int length=0;
        int count=0;
        int sum=0;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>k && i<j){
                // trim
                sum-=nums[i];
                i++;
            }
            if(sum==k){
                length=max(length,(j-i+1));
                count++;
            }
            j++;
        }
        return count;
        // return total no of such subarrays
    }

int main()
{
    int arr[] = {10, 5, 2, 7, 1, 9};
    int sumSubarr = 15;
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << "\n\nThe no of elem in arr with sum= " << sumSubarr << " is: " << lenOfLongSubarr_BruteForce(arr, n, sumSubarr);
    // cout << "\n\nThe no of elem in arr with sum= " << sumSubarr << " is: " << lenOfLongSubarr_Brute2(arr, n, sumSubarr);
    // cout << "\n\nThe no of elem in arr with sum= " << sumSubarr << " is: " << lenOfLongSubarr_Better(arr, n, sumSubarr);
    // cout << "\n\nThe no of elem in arr with sum= " << sumSubarr << " is: " << lenOfLongSubarr_Optimal(arr, n, sumSubarr);

    vector<int> nums = {1,2,1,2,1};
    int k=3;
    cout << "\n\nThe no of total subarray possible in arr with sum= " << k << " is: " << subarraySum(nums,k);

    return 0;
}