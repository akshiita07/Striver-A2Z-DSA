#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: 
long long brute_force(vector<int> &nums1, vector<int> &nums2, long long k)
{
    long long ans;
    int n = nums1.size();
    int m = nums2.size();
    vector<long long> products;

    // find all permuatations possible of products of nums1*nums2
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            products.push_back(static_cast<long long>(nums1[i]) * nums2[j]);
        }
    }

    // sort this array
    sort(products.begin(), products.end());

    ans = products[k - 1];

    return ans;
}

long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
{
    long long ans;
    int n = nums1.size();
    int m = nums2.size();
    // NOT COMPLETED!!  
    return ans;
}
int main()
{
    vector<int> nums1 = {-4, -2, 0, 3};
    vector<int> nums2 = {2, 4};
    int k = 6;
    cout << "\nBRUTE FORCE: The " << k << "th smallest product of nums1*nums2 is: " << kthSmallestProduct(nums1, nums2, k);

    return 0;
}