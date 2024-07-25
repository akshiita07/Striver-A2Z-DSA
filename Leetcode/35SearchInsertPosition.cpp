#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &arr, int target)
{
    int n = arr.size();
    return lower_bound(arr.begin(),arr.end(),target)-arr.begin();
}

int main()
{
    vector<int> arr = {1, 3, 5, 6};
    int target1 = 5; // Output: 2 as it exists
    int target2 = 2; // Output: 1: in sorted posititon
    cout << "\nSearching " << target1 << " in array at: " << searchInsert(arr, target1);
    cout << "\nSearching " << target2 << " in array at: " << searchInsert(arr, target2);

    return 0;
}