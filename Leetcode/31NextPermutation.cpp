#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE- GENERATE ALL PERMUTATIONS, LINEAR SEARCH FOR GIVEN arr PERMUTATION, THEN RETURN NEXT PERMUTATION
// time-  O(n!)       space- O()
// for 3 numbers-> 3! no of permutations possible
void permutationsRecursive(int arr[], int n, vector<int> &ds, vector<vector<int>> &ans, vector<bool> &hashMap)
{

    // BASE CASE:
    //  when size of ds==n then ans
    if (ds.size() == n)
    {
        ans.push_back(ds);
        return;
    }

    // a map is reqd to mark which element is already picked
    for (int i = 0; i < n; i++)
    {
        // if i in map is NOT MARKED then add in data str & mark it in mao
        if (!hashMap[i])
        { // not marked
            // put in ds
            ds.push_back(arr[i]);
            // mark in map
            hashMap[i] = true;
            // recursive
            permutationsRecursive(arr, n, ds, ans, hashMap);

            // remove whatever picked & false
            ds.pop_back();
            hashMap[i] = false;
        }
        // if map is MARKED
    }
} // TIME-O(n*n!)         space-O(n+n)-->extra map array+ds
void nextPermutation_Brute(int arr[], int n)
{
    vector<vector<int>> ans; // will store arrays of permutations
    vector<int> ds;
    vector<bool> hashMap(n, 0); // of size n ie initialised to 0

    // WRITE PERMUTATIONS IN SORTED ORDER-
    permutationsRecursive(arr, n, ds, ans, hashMap);

    cout << "\nPermutations are:\n";
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }

    cout << "\nThe next lexicographic permutation is:\n";
    // linear search
    bool found = false;
    for (auto i = 0; i < ans.size(); i++)
    {
        if (found)
        {
            for (auto ele : ans[i])
            {
                cout << ele << " ";
            }
            cout << "\n";
            return;
        }

        if (equal(arr, arr + n, ans[i].begin()))        //if elements in arr r equal
        {
            found = true;
        }
    }
}

// IN BUILT-->stl ie next_permutation(a.begin(),a.end())
void nextPermutation_Stl(vector<int> arr)
{
    next_permutation(arr.begin(), arr.end());

    cout << "\nThe next lexicographic permutation is:\n";
    for (auto it : arr)
    {
        cout << it << " ";
    }
}

// OPTIMAL- IMPLEMENTATION OF THIS IN BUILT STL
void nextPermutation_Optimal(int arr[], int n)
{
    vector<int> ans;

    // WRITE PERMUTATIONS IN SORTED ORDER-

    cout << "\nThe next lexicographic permutation is:\n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    nextPermutation_Brute(arr, n);

    vector<int> vec = {1, 2, 3};
    // nextPermutation_Stl(vec);

    return 0;
}