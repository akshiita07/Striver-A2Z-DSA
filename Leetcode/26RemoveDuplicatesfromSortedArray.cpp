#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[], int n)
{
    // if only 1 element is present in array then it will be unique
    if (n == 1)
    {
        return n;
    }
    vector<int> uniqueArr;

    cout << "Total no of elements in array are: " << n << endl;
    int k = 1; // no of elements in array after removing duplicates-> 1st elem is unique
    uniqueArr.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1]) // non unique
        {
            uniqueArr.push_back(arr[i]);
            k++;
        }
    }
    cout << "Total no of UNIQUE elements in array are: " << k << endl;
    for (auto it : uniqueArr)
    {
        cout << it << " ";
    }

    // push back in original array
    for (int i = 0; i < uniqueArr.size(); i++)
    {
        arr[i] = uniqueArr[i];
    }

    cout << "in original array : " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }

    return k;
}

// 2pointer approach- O(n) time & space-O(1)
int removeDuplicatesOptimal(vector<int> &nums)
{
    int i = 0;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[i] != nums[j])
        {
            nums[i + 1] = nums[j];
            i++;
        }
    }
    return (i + 1);
}

int main()
{
    int arr[] = {1, 1, 2};
    // int arr[] = {1, 1};
    // int arr[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Number of elements in array after removing duplicates are: " << removeDuplicates(arr, n);

    return 0;
}