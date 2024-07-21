#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: TIME-O(n*logn)-sort+O(2n)-loop        SPACE-O(n)-ans
void merge_brute(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int n = intervals.size();

    for (int i = 0; i < n; i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // if it is already inside new interval then move on next one
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            // check if within interval
            if (end >= intervals[j][0])
            {
                end = max(end, intervals[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }

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

// OPTIMAL: TIME-O(nlogn)-sort+O(n)        SPACE-O(n)-to store ans
void merge_optimal(vector<vector<int>> &intervals)
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
    // merge_brute(intervals);
    merge_optimal(intervals);

    return 0;
}