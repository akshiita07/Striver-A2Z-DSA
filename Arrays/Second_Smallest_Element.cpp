#include <bits/stdc++.h>
using namespace std;

// Second Largest Element in an Array without sorting
int print2largest(int arr[], int n)
{
    // Code Here
    int max = arr[0];
    int secondLarg = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "max element is: " << max << endl;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > secondLarg && arr[i] != max)
        {
            secondLarg = arr[i];
        }
    }
    cout << "\nSECOND LARGEst element is: " << secondLarg << endl;
    if (secondLarg)
    {
        return secondLarg;
    }
    else
    {
        return -1;
    }
    // TIME: O(n+n)=O(2n)       not optimal go 👇🏻
}

int getSecondLargestElements(int a[],int n)
{
    // Write your code here.
    int max = a[0];
    int sLarg = -1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            sLarg = max;
            max = a[i];
        }
        if (a[i] > sLarg && a[i] != max)
        {
            sLarg = a[i];
        }
    }
    cout << "max element is: " << max << endl;
    cout << "\nSECOND LARGEst element is: " << sLarg << endl;
    return sLarg;
    // TIME-O(n) OPTIMAL SOLN
}
// second smallest element:
int getSecondSmallestElement(int a[],int n)
{
    // Write your code here.
    int min = a[0];
    int sMin = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            sMin = min;
            min = a[i];
        }
        if (a[i] < sMin && a[i] != min)
        {
            sMin = a[i];
        }
    }
    cout << "min element is: " << min << endl;
    cout << "\nSECOND minimum element is: " << sMin << endl;
    return sMin;
    // TIME-O(n) OPTIMAL SOLN
}

int main()
{
    int arr[] = {1, 2, 4, 7, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    // print2largest(arr, n);
    getSecondLargestElements(arr,n);
    getSecondSmallestElement(arr,n);

    return 0;
}