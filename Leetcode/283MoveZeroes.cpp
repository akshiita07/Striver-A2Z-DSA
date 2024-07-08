#include <bits/stdc++.h>
using namespace std;

void moveZeroes(int arr[], int n)
{
    // TIME: O(n)        EXTRA SPACE-O(1)
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[j] = arr[i];
            // non zero elements
            j++;
        }
    }
    for(int i=j;i<n;i++){
        arr[i]=0;
    }
    // result
    cout << "\nAfter moving zeroes to right array is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    moveZeroes(arr, n);

    return 0;
}