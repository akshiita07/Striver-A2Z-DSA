#include <bits/stdc++.h>
using namespace std;
// find the number of subarrays of array ‘arr’ whose bitwise XOR( ⊕ ) of all elements is equal to ‘B’.
// XOR 0^0=0        O^A=A

// BRUTE FORCE:     TIME=O(n^3)     SPACE=O(1)
int subarraysWithSumK_brute(vector<int> arr, int b)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int xorAns = 0;
            for (int k = i; k <= j; k++)
            {
                xorAns = xorAns ^ arr[k];
            }
            if (xorAns == b)
            {
                count++;
            }
        }
    }
    return count;
}

// BETTER:     TIME=O(n^2)     SPACE=O(1)
int subarraysWithSumK_better(vector<int> arr, int b)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int xorAns = 0;
        for (int j = i; j < n; j++)
        {
            xorAns = xorAns ^ arr[j];
            if (xorAns == b)
            {
                count++;
            }
        }
    }
    return count;
}

// OPTIMAL:     TIME=O(n*1)-unordered map     SPACE=O(n)->map is used to store xor of earlier elements
// find x such that  x^k=XR         -> x=XR^k
// so to keep track of x -> use hash map
int subarraysWithSumK_optimal(vector<int> arr, int k)
{
    int n = arr.size();
    int count = 0;
    unordered_map<int,int> hashMap;     //xor,count
    int xorAns=0;
    hashMap[0]=1;

    for(int i=0;i<n;i++){
        xorAns=xorAns^arr[i];

        // find if x exists such that x=k^xorAns
        int x=k^xorAns;
        count+=hashMap[x];

        // add in map
        hashMap[xorAns]++;
    }
    return count;
}

int main()
{
    vector<int> arr = {1, 2, 3, 2};
    int b = 2;
    // cout << "No of subarrays in arr with XOR as " << b << " are: " << subarraysWithSumK_brute(arr, b);
    // cout << "No of subarrays in arr with XOR as " << b << " are: " << subarraysWithSumK_better(arr, b);
    cout << "No of subarrays in arr with XOR as " << b << " are: " << subarraysWithSumK_optimal(arr, b);

    return 0;
}