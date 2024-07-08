#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH USING SET-> UNIQUE+SORTED
void bruteforce(int arr1[], int arr2[], int n, int m)
{
    set<int> merged;
    for (int i = 0; i < n; i++)
    {
        merged.insert(arr1[i]);
    }
    for (int j = 0; j < m; j++)
    {
        merged.insert(arr2[j]);
    }
    // return set with correct order of elements
    cout << "\nAfter union set is:\n";
    for (auto it : merged)
    {
        cout << it << " ";
    }
    // TIME- O((n*logn)+(m*logm)+(n+m))
    // SPACE- O(n+m) for maintaining set
}

void findUnion(int arr1[], int arr2[], int n, int m)
{
    // Your code here
    vector<int> merged;
    int i = 0;
    int j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            // for first element also ADD IT 👇🏻
            if (merged.empty() || merged.back() != arr1[i])
            {
                // it also checks if it has not been earlier added!
                merged.push_back(arr1[i]);
            }
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            if (merged.empty() || merged.back() != arr2[j])
            {
                // it also checks if it has not been earlier added!
                merged.push_back(arr2[j]);
            }
            j++;
        }
    }

    // add remaining elements
    for (; i < n; i++)
    {
        if (merged.empty() || merged.back() != arr1[i])
        {
            merged.push_back(arr1[i]);
        }
    }
    for (; j < m; j++)
    {
        if (merged.empty() || merged.back() != arr2[j])
        {
            merged.push_back(arr2[j]);
        }
    }

    // return vector with correct order of elements
    cout << "\nAfter union:\n";
    for (auto it : merged)
    {
        cout << it << " ";
    }
    // TIME- O(n+m)
    // SPACE- O(n+m) for maintaing merged array to return d ans (not for storing)
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 6, 7};
    int n = 5;
    int m = 5;
    // bruteforce(arr1, arr2, n, m);
    findUnion(arr1, arr2, n, m);

    return 0;
}