#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH-        time:O(n)       extra spac:O(k)
void rotateArray(int arr[], int n, int k)
{
    k=k%n;              //if k=size then it returns same array so perform k%size no of rotations

    // push first k elements in a temp array
    vector<int> temp;
    for (int i = 0; i < k; i++)
    {
        temp.push_back(arr[i]);     //first k elements push
    }

    // -> shifting
    for (int i = k; i < n; i++)
    {
        arr[i-k]=arr[i];
    }

    // add remaining k elem at end
    for (int i = k+1; i < n; i++)
    {
        arr[i]=temp[i-(k+1)];
    }

    // print ans:
    cout << "\nAfter left rotation by " << k << " array is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// OPTIMAL-        time:O(2n)-> 3 reversals:(d)+(n-d)+(n)       extra spac:O(1)ie no extra space reqd
void rotateArrayOptimal(int arr[], int n, int k)
{
    k=k%n;              //if k=size then it returns same array so perform k%size no of rotations

    // 1. reverse first k elements: 0 to 2
    reverse(arr,arr+k);
    // 2. reverse k+1 to n elements: 3 to 6
    reverse(arr+k,arr+n);
    // 3. now reverse d  whole array: 0 to 6
    reverse(arr,arr+n);
    

    // print ans:
    cout << "\nOPTIMAL: After left rotation by " << k << " array is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // no of rotations to be performed
    // rotateArray(arr, n, k);                  //BRUTE FORCE
    rotateArrayOptimal(arr, n, k);                  //OPTIMAL

    return 0;
}