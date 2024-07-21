#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE- USING EXTRA MERGED ARRAY SO SPACE:O(m+n)        TIME-O(m+n)+O(m+n)
void merge_brute(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0;
    int j = 0;
    vector<int> merged;
    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            merged.push_back(nums1[i]);
            i++;
        }
        else
        {
            merged.push_back(nums2[j]);
            j++;
        }
    }
    // add remaining
    for (; i < m; i++)
    {
        merged.push_back(nums1[i]);
    }
    for (; j < n; j++)
    {
        merged.push_back(nums2[j]);
    }
    nums1 = merged;
    // ans must be in nums1
    cout << "The merged array in nums1 is: \n";
    for (int i = 0; i < m + n; i++)
    {
        cout << nums1[i] << " ";
    }
}

// OPTIMAL-i AT LAST INDEX & j at first index:SPACE-O(1)      TIME-O(min(m,n))-iterate+O(mlogm)+O(nlogn)->to sort
void merge_optimal1(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = 0;
    while (i >= 0 && j < n)
    {
        if (nums1[i] >= nums2[j])
        {
            swap(nums1[i], nums2[j]);
            i--;
            j++;
        }
        else
        {
            break;
        }
    }

    // individually sort both of them now
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    // ans must be in nums1 & nums2
    cout << "The merged array in nums1 is: \n";
    for (int i = 0; i < m; i++)
    {
        cout << nums1[i] << " ";
    }
    cout << "The merged array in nums2 is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << nums2[i] << " ";
    }
}

// OPTIMAL-using gap method:SPACE-O()      TIME-O()
void merge_optimal2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int gap = ceil((m + n) / 2);
    while (gap > 0)
    {
        int i = 0;
        int j = i + gap;
        while (j < m+n) // until right pointer goes out
        {
            // 2 different arrays to be compred

            // when i in nums1 & j in nums2
            if (i < m && j >= m)
            {
                if (nums1[i] >= nums2[j-m])
                {
                    swap(nums1[i], nums2[j-m]);
                }
            }
            // when i in nums2 & j in nums2
            else if (i >= m)
            {
                if (nums2[i-m] >= nums2[j-m])
                {
                    // in arr2- j would be j-m
                    swap(nums2[i-m], nums2[j-m]);
                }
            }
            // when i in nums1 & j in nums1
            else
            {
                if (nums1[i] >= nums1[j])
                {
                    swap(nums1[i], nums1[j]);
                }
            }
            // move ptr
            i++;
            j++;
        }
        if(gap==1){
            break;
        }
        gap = ceil(gap / 2);
    }

    // ans must be in nums1 & nums2
    cout << "The merged array in nums1 is: \n";
    for (int i = 0; i < m; i++)
    {
        cout << nums1[i] << " ";
    }
    cout << "The merged array in nums2 is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << nums2[i] << " ";
    }
}

int main()
{
    // vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums1 = {1, 2, 3};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    // merge_brute(nums1, m, nums2, n);
    // merge_optimal1(nums1, m, nums2, n);
    merge_optimal2(nums1, m, nums2, n);
    // Output: [1,2,2,3,5,6]

    return 0;
}