#include <bits/stdc++.h>
using namespace std;

vector<int> brute_force(vector<vector<int>> &items, vector<int> &queries)
{
    vector<int> ans;
    // items[i] = [pricei, beautyi]
    //  For each queries[j],determine the maximum beauty of an item whose price <= queries[j]
    int n = queries.size();
    // sort items by price:
    sort(items.begin(), items.end());
    // items = {{1, 2}, {2, 4}, {3, 2}, {3, 5}, {5, 6}};
    int m = items.size();
    for (int i = 0; i < n; i++)
    {
        // for query query[i] find items with price<=queries[i]
        int currentQuery = queries[i];
        int maxBeauty = 0;      //if not found
        int j = 0;
        while (j < m)
        {
            if (items[j][0] <= currentQuery)
            {
                j++;
            }else{
                break;
            }
        }
        // now i points to next element so dec i & find max
        for (int k = 0; k < j; k++)
        {
            // find max beauty:
            maxBeauty = max(maxBeauty, items[k][1]);
        }
        // replace query with this maxBeauty
        ans.push_back(maxBeauty);
    }
    return ans;
}
vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
{
    // items[i] = [pricei, beautyi]
    //  For each queries[j],determine the maximum beauty of an item whose price <= queries[j]
    int n = items.size();
    // sort items by price:
    sort(items.begin(), items.end());
    // items = {{1, 2}, {2, 4}, {3, 2}, {3, 5}, {5, 6}};
    int m = queries.size();

    // create vector with all beauty values:
    vector<int> beautyVector(n);
    beautyVector[0] = items[0][1];      //at 1st index

    // Build up the mostBeauty array
    for (int i = 1; i < n; i++){
        // take max beauty out of prev n next value
        beautyVector[i] = max(beautyVector[i - 1], items[i][1]);
    }

    vector<int> ans;     //queries size ka
    for (int i = 0; i < m; i++)
    {
        int currentQuery = queries[i];
        vector<int> &&target = {currentQuery, INT_MAX};
        // Use upper_bound to find the first item with a price > query
        int j = upper_bound(items.begin(), items.end(), target) - items.begin();
        // If j is 0, no items have price <= query
        if (j == 0){
            ans.push_back(0);
        }
        else
            ans.push_back(beautyVector[j - 1]);
    }

    return ans;
}

int main()
{
    vector<vector<int>> items = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
    vector<int> queries = {1, 2, 3, 4, 5, 6};
    // Output: [2,4,5,5,6,6]
    vector<int> ans = maximumBeauty(items, queries);
    cout << "Max beauties are: \n";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}