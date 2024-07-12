#include <bits/stdc++.h>
using namespace std;

// BRUTE- TIME-O(n)+O(n)            SPACE-O(n)
void rearrangeArray_brute(int arr[], int n)
{
    vector<int> ans;
    vector<int> positive;
    vector<int> negative;

    // add all + nos from arr to positive array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            positive.push_back(arr[i]);
        }
        else
        {
            negative.push_back(arr[i]);
        }
    }

    // add these +,- in order in ans array
    int i = 0;
    int j = 0;
    while (i < positive.size() && j < negative.size())
    {
        ans.push_back(positive[i]);
        i++;
        ans.push_back(negative[j]);
        j++;
    }
    // print modified array
    cout << "\nThe modified array is-\n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

// OPTIMAL - 1 PASS- TIME-O(n)            SPACE-O(n)
void rearrangeArray_optimal(int arr[], int n)
{
    vector<int> ans(n);
    int posInd=0;
    int negInd=1;

    // add all + nos from arr to positive array
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>=0)
        {
            // positive no
            ans[posInd]=arr[i];
            // add positive no at even place
            posInd+=2;
        }
        else
        {
            // add negative no at ODD place
            ans[negInd]=arr[i];
            negInd+=2;
        }
    }
    
    // print modified array
    cout << "\nThe modified array is-\n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

int main()
{
    int arr[] = {3, 1, -2, -5, 2, -4};
    int n = sizeof(arr) / sizeof(arr[0]);
    // rearrangeArray_brute(arr, n);
    rearrangeArray_optimal(arr, n);

    return 0;
}