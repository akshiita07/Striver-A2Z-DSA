#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE- GENERATE ALL PERMUTATIONS, LINEAR SEARCH FOR GIVEN arr PERMUTATION, THEN RETURN NEXT PERMUTATION
// time-  O(n!)       space- O()
// for 3 numbers-> 3! no of permutations possible
void nextPermutation_Brute(int arr[], int n)
{
    vector<int> ans;

    // WRITE PERMUTATIONS IN SORTED ORDER-

    cout << "\nThe next lexicographic permutation is:\n";
    for (auto it : ans)
    {
        cout << it << " ";
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
    int n=sizeof(arr)/sizeof(arr[0]);
    // nextPermutation_Brute(arr, n);

    vector<int> vec = {1, 2, 3};
    nextPermutation_Stl(vec);

    return 0;
}