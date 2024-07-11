#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE- TIME:O(nlogn)     SPACE-O(1)
int pivotFnc(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i < high)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int partPos = pivotFnc(arr, low, high);
    quickSort(arr, low, partPos - 1);
    quickSort(arr, partPos + 1, high);
}
void sortColors_Brute(int arr[], int n)
{
    quickSort(arr, 0, n - 1);
    // use quick sort for O(nlogn) time
    // print sorted ans
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// BETTER APPROACH- ITERATE ONCE & KEEP A COUNT-        TIME-O(n+n)=O(2n)        SPACE-O(1)
void sortColors_better(int arr[], int n)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        else if (arr[i] == 1)
        {
            count1++;
        }
        else if (arr[i] == 2)
        {
            count2++;
        }
    }
    for (int i = 0; i < count0; i++)
    {
        arr[i] = 0;
    }
    for (int i = count0; i < count0 + count1; i++)
    {
        arr[i] = 1;
    }
    for (int i = count0 + count1; i < count0 + count1 + count2; i++)
    {
        arr[i] = 2;
    }
    // print sorted ans
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// OPTIMAL APPROACH- DUTCH NATIONAL FLAG ALGO        TIME-O()       SPACE-O()
void sortColors_optimal(int arr[], int n)
{
    // 3 RULES- 0 TO LOW-1-->0s             LOW TO MID-1-->1s           MID TO HIGH-->lunsorted     HIGH+1-n-1-->2s
    // 3CASES- if arr[mid]=0--> 1.swap(arr[low],arr[mid]),low++,mid++        =1-->mid++       =2-->swap(arr[high],arr[mid]),high--
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    { // stop when mid crosses high
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    // print sorted ans
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {2, 0, 2, 1, 1, 0};
    // op: 0,0,1,1,2,2
    int n = sizeof(arr) / sizeof(arr[0]);

    // sortColors_Brute(arr, n);
    // sortColors_better(arr, n);
    sortColors_optimal(arr, n);

    return 0;
}