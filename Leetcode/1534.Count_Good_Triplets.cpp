#include <bits/stdc++.h>
using namespace std;

int countGoodTriplets(vector<int> &arr, int a, int b, int c)
{
    // find the number of good triplets
    // good triplet arr[i],arr[j],arr[k] if 0<=i<j<k<arr.size() & |arr[i] - arr[j]| <= a, |arr[j] - arr[k]| <= b, |arr[i] - arr[k]| <= c
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{
    vector<int> arr = {3, 0, 1, 1, 9, 7};
    int a = 7;
    int b = 2;
    int c = 3;
    cout << "\n no of good triplets=" << countGoodTriplets(arr, a, b, c);
    // ans 4

    return 0;
}