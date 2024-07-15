#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE      TIME-O(n^2)      SPACE-O(1)-NO EXTRA SPACE
int longestConsecutive_brute(int arr[], int n)
{
    int maxlength = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int length = 1;
        int elem = arr[i];
        cout << "First ele is: " << elem << endl;

        bool found = false;
        while (!found)
        {
            found = true; // assume v found
            for (int j = 0; j < n; j++)
            {
                if (elem + 1 == arr[j] && j != i)
                {
                    elem++;
                    length++;
                    found = false; // exit loop
                    break;
                }
            }
        }
        maxlength = max(maxlength, length);
    }

    return maxlength;
}

// BETTER     TIME-O(nlogn+n)      SPACE-O(1)
int longestConsecutive_better(int arr[], int n)
{
    // first sort array
    sort(arr, arr + n);
    // arr-1,1,1,2,2,2,3,3,4,100,100,101,101,102
    int maxlength = 0;
    int length = 1;
    int lastSmallest = INT_MIN;

    for (int i = 0; i < n; i++)
    {

        // is next element ka prev=lastSmallest?
        if (arr[i] - 1 == lastSmallest)
        {
            // inc length
            length++;
            // add it as a part of sequence
            lastSmallest = arr[i];
        }
        else if (arr[i] == lastSmallest) // if both r equal eg:1,1
        {
            // do nothing
        }
        else if (arr[i] != lastSmallest) // if change in sequence: 4,100
        {
            // restart length
            length = 1;
            lastSmallest = arr[i];
        }
        maxlength = max(maxlength, length);
    }

    return maxlength;
}

// OPTIMAL     TIME-O(n+2n)      SPACE-O(n)-->set
int longestConsecutive_optimal(int arr[], int n)
{
    // add all elem of array into an unordered set
    unordered_set<int> arrSet;
    for (int i = 0; i < n; i++)
    {
        arrSet.insert(arr[i]);
    }
    int maxlength = INT_MIN;

    for (auto it : arrSet)
    {
        if (arrSet.find(it - 1) == arrSet.end())
        {
            // ie previous element does NOT exist--> so it is first element
            int elem = it;
            int length = 1;

            // check if next elem exists n inc count
            while (arrSet.find(elem + 1) != arrSet.end())
            { // next elem also present
                length++;
                elem++;
            }
            maxlength = max(maxlength, length);
        }
        else if (arrSet.find(it - 1) != arrSet.end())
        {
            // ie previous element exists--> do nothing
        }
    }

    return maxlength;
}

int main()
{
    int arr1[] = {100, 4, 200, 1, 3, 2};              // 4
    int arr2[] = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};      // 9
    int arr3[] = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6}; // 7
    int arr4[] = {100, 102, 100, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int n4 = sizeof(arr4) / sizeof(arr3[4]);

    // cout << "\nLength of consecutive sequence is: " << longestConsecutive_brute(arr3, n3) << endl;
    // cout << "\nLength of consecutive sequence is: " << longestConsecutive_better(arr4, n4) << endl;
    cout << "\nLength of consecutive sequence is: " << longestConsecutive_optimal(arr3, n3) << endl;

    return 0;
}