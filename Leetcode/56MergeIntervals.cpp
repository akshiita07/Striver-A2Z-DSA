#include <bits/stdc++.h>
using namespace std;

void merge_brute(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int n = intervals.size();
    vector<int> temp = intervals[0]; // first interval inside temp

    for (int i = 1; i < n; i++)
    {

        if (intervals[i][0] > temp[1])
        {
            // interval remain same
            // ans.push_back({intervals[i][0], intervals[i][1]}, {intervals[i + 1][0], intervals[i + 1][1]});
            ans.push_back(temp);
            temp = intervals[i];
        }
        else
        {
            // if intervals[i][0] <= temp[1]

            // merge interval
            temp[1] = max(temp[1], intervals[i][1]);
        }
    }
    ans.push_back(temp);

    cout << "The overlapping intervals are: \n";
    for (auto row : ans)
    {
        for (auto it : row)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // Output: [[1,6],[8,10],[15,18]]
    merge_brute(intervals);

    return 0;
}