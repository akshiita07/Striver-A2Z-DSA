#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE:
vector<int> mergeSort(vector<int> &arr1, vector<int> &arr2)
{
    int i = 0;
    int j = 0;
    vector<int> merged;
    int n = arr1.size();
    int m = arr2.size();
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            merged.push_back(arr1[i]);
            i++;
        }
        else
        {
            merged.push_back(arr2[j]);
            j++;
        }
    }
    // remaining
    for (; i < n; i++)
    {
        merged.push_back(arr1[i]);
    }
    for (; j < m; j++)
    {
        merged.push_back(arr2[j]);
    }
    return merged;
}
int brute_force(vector<int> &arr1, vector<int> &arr2, int k)
{
    vector<int> merged = mergeSort(arr1, arr2);
    return merged[k - 1];
}

// BINARY SEARCH:
int kthElement(vector<int> &arr1, vector<int> &arr2, int k)
{
    int n = arr1.size();
    int m = arr2.size();
    int noOfElemOnLeft = k; // keep k no of elem on left

    if (n > m)
    {
        // apply bin search for min no of elements
        return kthElement(arr2, arr1, k);
    }
    int low = max(0, k - m);
    int high = min(k, n);

    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = noOfElemOnLeft - mid1;

        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if (mid1 < n)
        {
            r1 = arr1[mid1];
        }
        if (mid2 < m)
        {
            r2 = arr2[mid2];
        }
        if (mid1 - 1 >= 0)
        {
            l1 = arr1[mid1 - 1];
        }
        if (mid2 - 1 >= 0)
        {
            l2 = arr2[mid2 - 1];
        }

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
        {
            // high ko kam karo
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return 0;
}

int main()
{
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int k = 5;
    cout << "\nBRUTE FORCE: The " << k << "th element in merged arr1 and arr2 is: " << brute_force(arr1, arr2, k);
    cout << "\nThe " << k << "th element in merged arr1 and arr2 is: " << kthElement(arr1, arr2, k);

    return 0;
}