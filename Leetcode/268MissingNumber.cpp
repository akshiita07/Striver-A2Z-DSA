#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: time:O(n^2)
int missingNumber_BruteForce(int nums[], int n)
{
    // find m: maxm no
    int m = nums[0];
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > m)
        {
            m = nums[i];
        }
    }
    // m stores 3

    // check if array cts all nos from 0 to m--> 0 to 3
    for (int i = 0; i <= m; i++)
    {
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            // 0,1,2,3
            if (nums[j] == i)
            {
                cout << "Found " << i << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            return i;
        }
    }

    // if no missing no then -1
    return -1;
}

// OPTIMIZE: SUM
// TIME-O(n)        SPACE-O(1)
int missingNumberSum(int nums[], int n)
{
    // find m: maxm no
    int m = nums[0];
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > m)
        {
            m = nums[i];
        }
    }
    // m stores 3

    // find sum of first m numbers:
    int sumOfFirstM=(m*(m+1))/2;

    // find sum of array
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }

    // missing elem will be difference of sum & sumOfFirstM
    return sumOfFirstM-sum;
}

// MOST OPTIMAL- XOR
// TIME-O(n)--> even better for larger nos        SPACE-O(1)
int missingNumberXOR(int nums[], int n)
{
    // find m: maxm no
    int m = nums[0];
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > m)
        {
            m = nums[i];
        }
    }
    // m stores 3

    int XOR1=0; //for looping from 0 to m
    int XOR2=0; //for looping thru array
    for(int i=0;i<n;i++){
        XOR2=XOR2^nums[i];
        XOR1=XOR1^(i);
    }
    XOR1=XOR1^n;
    
    return XOR1^XOR2;
}

int main()
{
    int nums[] = {3, 0, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    // cout << "The missing number is: " << missingNumber_BruteForce(nums, n);
    // cout << "The missing number is: " << missingNumberSum(nums, n);
    cout << "The missing number is: " << missingNumberXOR(nums, n);

    return 0;
}