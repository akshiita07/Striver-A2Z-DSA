#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: TIME:O(n^2)         SPACE:LIST WITH MAX OF 2 ELEMENTS-O(2) SO CONST SPACE
void majorityElement_brute(vector<int> &arr)
{
    int n = arr.size();
    int limit = int(n / 3);
    cout << "Limit is " << limit << endl;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }

        if (ans.size() == 2)
        {
            break;
            // as list can contain max of 2 elements
        }
        else if (count > limit)
        {
            ans.push_back(arr[i]);
        }
    }

    cout << "Elements that appear more than n/3 times are: \n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

// BETTER->HASHING: TIME:O(n*1) best case   but worst:O(n*n)        SPACE- EXTRA MAP: O(n)
void majorityElement_better(vector<int> &arr)
{
    int n = arr.size();
    int limit = int(n / 3);
    cout << "Limit is " << limit << endl;
    vector<int> ans;
    unordered_map<int, int> hashMap; // element,count
    for (int i = 0; i < n; i++)
    {
        hashMap[arr[i]] += 1;
        if (hashMap[arr[i]] == limit + 1) // occurs min of n/3+1 times
        {
            ans.push_back(arr[i]);
        }
        if (ans.size() == 2)
        {
            break;
            // as list can contain max of 2 elements
        }
    }

    cout << "Elements that appear more than n/3 times are: \n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

// OPIMAL: TIME:O(n)         MOORE'S VOTING ALGO
void majorityElement_optimal(vector<int> &arr)
{
    int n = arr.size();
    int limit = int(n / 3);
    cout << "Limit is " << limit << endl;
    vector<int> ans;
    int element1;
    int count1 = 0;
    int element2;
    int count2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (count1 == 0 && arr[i] != element2)
        {
            element1 = arr[i];
            count1 = 1;
        }
        else if (count2 == 0 && arr[i] != element1)
        {
            element2 = arr[i];
            count2 = 1;
        }
        else if (arr[i] == element1)
        {
            count1++;
        }
        else if (arr[i] == element2)
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    // verify
    int count1Verify = 0;
    int count2Verify = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element1)
        {
            count1Verify++;
        }
        else if (arr[i] == element2)
        {
            count2Verify++;
        }
    }
    if (count1Verify > limit)
    {
        ans.push_back(element1);
    }
    if (count2Verify > limit)
    {
        ans.push_back(element2);
    }

    cout << "Elements that appear more than n/3 times are: \n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

int main()
{
    // vector<int> arr = {3, 2, 3};
    vector<int> arr = {1, 2};
    // majorityElement_brute(arr);
    // majorityElement_better(arr);
    majorityElement_optimal(arr);

    return 0;
}