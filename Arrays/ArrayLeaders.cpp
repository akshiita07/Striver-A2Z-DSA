#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE; TIME-O(n^2)
void leaders_brute(int arr[], int n)
{
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        bool isLeader = true; // so that rightmost element is also inserted
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                isLeader = false;
                break;
            }
        }

        if (isLeader)
        {

            ans.push_back(arr[i]);
        }
    }

    // print all leaders from ans
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

// OPTIMAL; TIME-O(n)
void leaders_optimal(int arr[], int n)
{
    vector<int> ans;
    int maxi = INT_MIN;

    for (int i = n - 1; i >= 0; i--)
    {
        // select element
        int elem = arr[i];
        cout << "The element is: " << elem << endl;

        if (elem >= maxi)
        {
            ans.push_back(elem);
        }
        maxi = max(maxi, elem);
        // select max element from right
        cout << "The max element on right is: " << maxi << endl;
    }

    // print all leaders from ans
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

int main()
{
    int arr1[] = {16, 17, 4, 3, 5, 2};
    int arr2[] = {10, 4, 2, 4, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // leaders_brute(arr2, n2);
    leaders_optimal(arr1, n1);

    return 0;
}