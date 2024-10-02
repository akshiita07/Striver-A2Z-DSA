#include <bits/stdc++.h>
using namespace std;

vector<int> arrayRankTransform(vector<int> &arr)
{
    if (arr.empty())
    {
        return {};
    }
    vector<int> ans;
    unordered_map<int, int> hashMap;
    // sort array
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    // {10,10,20,30,40}
    int rank = 1;
    hashMap[sortedArr[0]] = rank;
    for (int i = 1; i < sortedArr.size(); i++)
    {
        if (sortedArr[i] == sortedArr[i - 1])
        {
            // no change of rank
        }
        else if (sortedArr[i] > sortedArr[i - 1])
        {
            // change of rank
            rank++;
        }
        hashMap[sortedArr[i]] = rank;
    }
    // now from hashMap map back to arr:
    for (int i = 0; i < arr.size(); i++)
    {
        ans.push_back(hashMap[arr[i]]);
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {40, 10, 20, 30};
    cout << "\nRank is: ";
    vector<int> ans1 = arrayRankTransform(arr1);
    for (auto it : ans1)
    {
        cout << it << " ";
    }
    cout << endl;
    vector<int> arr2 = {100, 100, 100};
    cout << "\nRank is: ";
    vector<int> ans2 = arrayRankTransform(arr2);
    for (auto it : ans2)
    {
        cout << it << " ";
    }

    return 0;
}