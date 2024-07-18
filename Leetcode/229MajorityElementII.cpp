#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: TIME:O(n^2)
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
        if (count > limit)
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

// BETTER->HASHING: TIME:O(n*1) best case
void majorityElement_better(vector<int> &arr)
{
    int n = arr.size();
    int limit = int(n / 3);
    cout << "Limit is " << limit << endl;
    vector<int> ans;
    unordered_map<int, int> hashMap; // element,count
    for (int i = 0; i < n; i++)
    {
        hashMap[arr[i]]++;
    }
    for (auto it : hashMap)
    {
        if (it.second > limit)
        {
            ans.push_back(it.first);
        }
    }

    cout << "Elements that appear more than n/3 times are: \n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

// OPIMAL: TIME:O()
void majorityElement_optimal(vector<int> &arr)
{
    int n = arr.size();
    int limit = int(n / 3);
    cout << "Limit is " << limit << endl;
    vector<int> ans;

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