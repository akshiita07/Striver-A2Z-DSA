#include <bits/stdc++.h>
using namespace std;

vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    vector<int> ans;

    // first loop thru all queries
    for (int i = 0; i < queries.size(); i++)
    {
        // select a particular query
        vector<int> query = queries[i];
        // loop from start to end of this first query
        int XOR = 0;        //xor with no leads number itself
        for (int j = query[0]; j <= query[1]; j++)
        {
            // i will iterate from 0 to 1 in arr to find xor
            XOR = XOR ^ arr[j];
        }
        ans.push_back(XOR);
    }

    cout << "\nThe XOR of queries yields: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 4, 8};
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};
    // Output: [2,7,14,8]
    xorQueries(arr, queries);
    return 0;
}