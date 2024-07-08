#include <bits/stdc++.h>
using namespace std;

void rotateArray(int arr[], int n)
{
    int k=arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i-1] = arr[i];
    }
    arr[n-1]=k;
    cout << "After left rotation by 1 array is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // TIME- O(n)
    // extra SPACE- O(1)              no extra space reqd               modifying original array only
    // but in problem SPACE- O(n)         modifying original array so O(n)
}

int main()
{
    int arr[] = {3, 1, 6, 5, 10, 7, 6, 6, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    rotateArray(arr, n);

    return 0;
}