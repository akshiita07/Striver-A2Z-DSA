#include <bits/stdc++.h>
using namespace std;

// no of +&- are not same-- so add remaining at end without altering order
void alternateNumbers(int arr[], int n)
{
    vector<int> ans;
    vector<int> positive;
    vector<int> negative;
    // TIME-O(n)- GET +&-VES
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
    int i = 0;
    int j = 0;
    // TIME-O(n)
    while (i < positive.size() && j < negative.size())
    {
        ans.push_back(positive[i]);
        i++;
        ans.push_back(negative[j]);
        j++;
    }
    // for remaning
    // TIME-O(n)
    for (; i < positive.size(); i++)
    {
        ans.push_back(positive[i]);
    }
    for (; j < negative.size(); j++)
    {
        ans.push_back(negative[j]);
    }

    // print modified array
    cout << "\nThe modified array is-\n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}
// TOTAL TIME-O(  )

int main()
{
    int arr[] = {1, 2, -4, -5, 3, 4};
    // int arr[] = {1, 2, -3, -1, -2, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    alternateNumbers(arr, n);

    return 0;
}