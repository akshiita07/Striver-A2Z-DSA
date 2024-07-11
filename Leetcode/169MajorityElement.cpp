#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE- TIME-O(n^2)     SPACE-O(1)
int majorityElement_Brute(int arr[], int n)
{
    // choose element & find its count
    for (int i = 0; i < n - 1; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }

        if (count > (n / 2))
        {
            return arr[i];
        }
    }
}

// Better- hashing-count no of times element occurs TIME-O(n*logn)+O(n)--> if unordered map-O(n)+O(n)     SPACE-O(n)-->map
int majorityElement_Better(int arr[], int n)
{
    map<int, int> hashMap;
    for (int i = 0; i < n; i++)
    {
        hashMap[arr[i]] += 1;
    }
    for (auto it : hashMap)
    {
        if (it.second > (n / 2))
        {
            return it.first;
        }
    }
    return -1;
}

// OPTIMAL- MOORES VOTING ALGO TIME-O()     SPACE-O(1)
int majorityElement_Optimal(int arr[], int n)
{
    int element;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            element = arr[i];
            count = 1;
        }
        else if (arr[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    int cVerify = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            cVerify++;
        }
    }
    if (cVerify > (n / 2))
    {
        return element;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int arr[] = {2, 2, 1, 1, 1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << "The majority element is: " << majorityElement_Brute(arr, n);
    cout << "The majority element is: " << majorityElement_Better(arr, n);

    return 0;
}