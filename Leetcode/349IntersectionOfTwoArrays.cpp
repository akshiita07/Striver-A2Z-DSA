#include <bits/stdc++.h>
using namespace std;

void intersection(int arr1[], int arr2[], int n, int m)
{
    // if these arrays r not sorted then first--> sort(arr.begin(),arr.end())
    vector<int> intersectArr;
    int i = 0;
    int j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            // if (intersectArr.empty() || intersectArr.back() != arr1[i])      //if only unique elements r allowed
            // {
                intersectArr.push_back(arr1[i]);
            // }
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    // print result
    cout << "\nThe intersection of 2 arrays is:\n";
    for (auto it : intersectArr)
    {
        cout << it << " ";
    }

    // TIME: O(n+m)     worst case
    // EXTRA SPACE: O(1)    no extra space reqd
}
int main()
{
    int arr1[] = {1, 2, 2, 2, 3, 4};
    int arr2[] = {2, 2, 3, 3};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    intersection(arr1, arr2, n, m);

    return 0;
}