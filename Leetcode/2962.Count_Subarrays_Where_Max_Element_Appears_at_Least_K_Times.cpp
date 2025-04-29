#include <bits/stdc++.h>
using namespace std;

// Time: O(n³)
long long brute_force(vector<int> &nums, int k)
{
    int maxi = *max_element(nums.begin(), nums.end());
    cout << "\nMax element of array nums is: " << maxi;
    // return no of subarrays where this maxi appears at least k times
    long long ans = 0;
    int n = nums.size();
    // generate all subarrays
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // check if subarrays has maxi at least k times
            int cnt = 0;
            for (int l = i; l <= j; l++)
            {
                if (nums[l] == maxi)
                {
                    cnt++;
                }
            }
            if (cnt >= k)
            {
                ans++;
            }
        }
    }
    return ans;
}

// Time: O(n)
long long countSubarrays(vector<int> &nums, int k)
{
    int maxi = *max_element(nums.begin(), nums.end());
    cout << "\nMax element of array nums is: " << maxi;
    // return no of subarrays where this maxi appears at least k times
    long long ans = 0;
    int n = nums.size();
    int cnt = 0;
    int i = 0;
    // i:left j:right pointers
    for (int j = 0; j < n; j++)
    {
        if (nums[j] == maxi)
        {
            cnt++;
        }
        // cnt must be atleast k ie cnt>=k
        while (cnt >= k)
        {
            if (nums[i] == maxi)
            {
                cnt--;
            }
            i++;
        }
        ans += i;
    }

    return ans;
}
/* Dry run:
k=2
nums:
0   1   2   3   4
1   3   2   3   3

maxi=3
n=5
ans=0
cnt=0
i=0 j=0

j=0 cnt=0 i=0 ans+=0=0
j=1 cnt=1 i=0 ans+=0=0
j=2 cnt=1 i=0 ans+=0=0
j=3 cnt=2 nums[i]!=maxi i=1 cnt=2
          nums[i]==maxi i=2 cnt=2-1=1
          ans+=2=2
j=4 cnt=2 nums[i]!=maxi i=3 cnt=2
          nums[i]==maxi i=4 cnt=2-1=1
    ans+=2+4=6

*/

int main()
{
    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2;
    cout << "\nbrute_force Count of subarrays where max element appears at least k times: " << brute_force(nums, k);
    cout << "\n";
    cout << "\nCount of subarrays where max element appears at least k times: " << countSubarrays(nums, k);

    return 0;
}