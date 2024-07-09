#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(int arr[], int n)
{
    int count = 0;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
            if (count > max)
            {
                max = count;
            }
            cout << "Count is: " << count << " & max is: " << max << endl;
        }
        else
        {
            count = 0;
            cout << "Count is: " << count << " & max is: " << max << endl;
        }
    }

    return max;
}

int main()
{
    // int arr[] = {0};
    int arr[] = {1, 1, 0, 1, 1, 1};
    // int arr[] = {1,0,1,1,0,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The no of max consecutive 1s are: " << findMaxConsecutiveOnes(arr, n);

    return 0;
}