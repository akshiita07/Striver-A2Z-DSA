#include <bits/stdc++.h>
using namespace std;

long long brute_force(vector<int> &nums1, vector<int> &nums2, long long k)
{
    // try all permutations of product & select k smallest one
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

// optimal:
long long countLessEqual(vector<int> &A, vector<int> &B, long long x)
{
    int n = A.size();
    int m = B.size();
    long long count = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0)
        {
            if (x >= 0)
            {
                count += m;
            }
        }
        else if (A[i] > 0)
        {
            // binary search in B for max B[j] such that A[i]*B[j] ≤ x
            int l = 0;
            int r = m - 1;
            int j = -1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if ((long long)A[i] * B[mid] <= x)
                {
                    j = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            count += (j + 1);
        }
        else
        {
            // A[i] < 0 → we want min B[j] such that A[i]*B[j] ≤ x
            int l = 0;
            int r = m - 1;
            int j = m;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if ((long long)A[i] * B[mid] <= x)
                {
                    j = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            count += (m - j);
        }
    }
    return count;
}

long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    long long low = -1e10;
    long long high = 1e10;
    long long ans;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (countLessEqual(nums1, nums2, mid) >= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {-4, -2, 0, 3};
    vector<int> nums2 = {2, 4};
    long long k = 6;
    cout << "\nbrute_force The kth smallest product is: " << brute_force(nums1, nums2, k);
    cout << "\nThe kth smallest product is: " << kthSmallestProduct(nums1, nums2, k);

    return 0;
}