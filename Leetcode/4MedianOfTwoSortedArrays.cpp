#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE:
vector<int> mergeSort(vector<int> &nums1, vector<int> &nums2)
{

    int m = nums1.size();
    int n = nums2.size();
    vector<int> merged;

    int i = 0;
    int j = 0;

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
    // remaining
    for (; i < m; i++)
    {
        merged.push_back(nums1[i]);
    }
    for (; j < n; j++)
    {
        merged.push_back(nums2[j]);
    }
    return merged;
}
double brute_force(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();

    vector<int> merged = mergeSort(nums1, nums2);
    cout << "The merged array using merge sort is: " << endl;
    for (auto it : merged)
    {
        cout << it << " ";
    }

    // if(m+n) is even then sum of 2 middle elements/2
    // if(m+n) is odd then return middle element
    double median;
    if (merged.size() % 2 == 0)
    {
        // even
        int index = merged.size() / 2; // int
        int fno = merged[index - 1];
        int sno = merged[index];
        median = (fno + sno) / (2.0);
    }
    else
    {
        int index = merged.size() / 2; // int
        median = merged[index];
    }

    return median;
}

// TIME: O(m+n)
double better_soln(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    double median;
    int pointer = 0; // index we r looking for

    int i = 0;
    int j = 0;

    int index2 = (m + n) / 2; // int
    int index1 = index2 - 1;
    int fno = -1; // initially set to -1
    int sno = -1; // initially set to -1

    while ((i < m && j < n) && (fno == -1 || sno == -1))
    {
        if (nums1[i] <= nums2[j])
        {
            if (pointer == index1)
            {
                fno = nums1[i];
            }
            if (pointer == index2)
            {
                sno = nums1[i];
            }
            pointer++; // now looking for next index
            i++;
        }
        else
        {
            if (pointer == index1)
            {
                fno = nums2[j];
            }
            if (pointer == index2)
            {
                sno = nums2[j];
            }
            pointer++; // now looking for next index
            j++;
        }
    }
    // remaining
    for (; i < m; i++)
    {
        if (pointer == index1)
        {
            fno = nums1[i];
        }
        if (pointer == index2)
        {
            sno = nums1[i];
        }
        pointer++; // now looking for next index
    }
    for (; j < n; j++)
    {
        if (pointer == index1)
        {
            fno = nums2[j];
        }
        if (pointer == index2)
        {
            sno = nums2[j];
        }
        pointer++; // now looking for next index
    }

    // if(m+n) is even then sum of 2 middle elements/2
    if ((m + n) % 2 == 0)
    {
        // even
        median = (double)(fno + sno) / (2.0);
    }
    else
    {
        // if(m+n) is odd then return middle element
        median = sno;
    }

    return median;
}

// BINARY SEARCH
// TIME: O(log2(min(m,n)))
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() > nums2.size())
    {
        // perform binary search on shorted length array
        return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size();
    int n = nums2.size();
    int low = 0;
    int high = m; // max from nums1
    int noOfELementsOnLeft = (m + n + 1) / 2;
    int sum = m + n;
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        // pick MID1 no of elements from nums1 like 0,1,2,___ & check if valid sorting is formed
        // from nums2 u can now take (((m+n)/2)-mid)
        int mid2 = (noOfELementsOnLeft - mid1);
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;

        // check index & assign values
        if (mid1 < m)
        {
            r1 = nums1[mid1];
        }
        if (mid2 < n)
        {
            r2 = nums2[mid2];
        }
        if (mid1 - 1 >= 0)
        {
            l1 = nums1[mid1 - 1];
        }
        if (mid2 - 1 >= 0)
        {
            l2 = nums2[mid2 - 1];
        }

        if (l1 <= r2 && l2 <= r1)
        {
            // all fine
            if (sum % 2 == 0)
            {
                // even
                return (max(l1, l2) + min(r1, r2)) / (2.0);
            }
            else
            {
                // odd
                return max(l1, l2);
            }
        }
        else if (l1 > r2)
        {
            // 7>3 & we choose mid=4
            high = mid1 - 1; // nums1 se LESS elements lo
        }
        else
        {
            // 6>4 & we choose mid=2
            low = mid1 + 1; // nums1 se zyada elements lo
        }
    }
    return 0;
}

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << "\nBRUTE FORCE:  The median is: " << brute_force(nums1, nums2);
    cout << "\nBETTER:  The median is: " << better_soln(nums1, nums2);
    cout << "\nOPTIMAL:  The median is: ";
    cout<<findMedianSortedArrays(nums1, nums2);

    return 0;
}