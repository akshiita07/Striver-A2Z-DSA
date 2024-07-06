#include <bits/stdc++.h>
using namespace std;

// find minimum element then swap it
void selectionSort(int arr[], int n)
{
    // find min elem from array
    for (int i = 0; i < n - 1; i++)
    { // n elements so (n-1)passes ->NOT FOR LAST ELEMENT
        int min = INT_MAX;
        int minIndex;
        for (int j = i; j < n; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                minIndex = j; // TO GET MIN INDEX WHERE D MIN VALUE IS STORED
            }
        }
        cout << "The minimum element of array is: " << min << " at index: " << minIndex << endl;

        swap(arr[i], arr[minIndex]);
    }

    // Print result
    cout << "\nAfter SELECTION sort  array is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// find MAXIMUM element then swap adjacent members
void bubbleSort(int arr[], int n)
{
    bool didSwap = false; // to optimize time to O(n) if already sorted array is given
    for (int i = 0; i < n - 1; i++)
    { // n elements ke n-1 passes
        // adjacent members check & swap
        for (int j = 0; j < n - 1; j++) // do not check for last element as for i=5 i+1 does not exists so n-1
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = true; // swap occurred
            }
        }

        if (didSwap == false)
        {
            // in 1st pass no swaps were performed ie already sorted array is given so ime reduced from O(n^2) to O(n)
            break;
        }
    }

    // Print result
    cout << "\nAfter BUBBLE sorting array is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void insertionSort(int arr[], int n)
{

    // select each element
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }

    // Print result
    cout << "\nAfter INSERTION sort array is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {14, 9, 15, 12, 6, 8, 13};
    // int arr[] = {1,2,3,4,5,6};       //when already sorted array is given
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\nBEFORE sorting array is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // selectionSort(arr, n);
    // TIME COMPLEXITY: O(n^2)

    // bubbleSort(arr, n);
    // TIME COMPLEXITY: O(n^2)worst/avg & best case using didSwap is O(n)

    insertionSort(arr, n);
    // TIME COMPLEXITY: O(n^2)worst if in descending order/avg & best case is O(n) when array is already sorted

    return 0;
}