#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x)
{
    int n = arr.size();
    int ans = n;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
        {
            // possible ans but not sure if smallest
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] <= x)
        {
            // move to right
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 4, 7, 7, 10};
    int x = 7;
    cout << "The index of UPPER bound is: " << upperBound(arr, x);

    return 0;
}