#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE      TIME-O()
int longestConsecutive_brute(int arr[], int n)
{
    int length = 1;
    int maxlength = INT_MIN;

    sort(arr, arr + n);

    // find if next elem to 1 is present
    int mini = arr[0];
    cout << "First min ele is: " << mini << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mini + j == arr[j])
            {
                length++;
                maxlength = max(maxlength, length);
                break;
            }
            else
            {
                length = 1;
                break;
            }
        }
    }

    return maxlength;
}

int main()
{
    int arr1[] = {100, 4, 200, 1, 3, 2};              // 4
    int arr2[] = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};      // 9
    int arr3[] = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6}; // 9
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    cout << "\nLength of consecutive sequence is: " << longestConsecutive_brute(arr2, n2) << endl;
    return 0;
}