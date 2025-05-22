#include <bits/stdc++.h>
using namespace std;

int brute_force(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    int m = queries.size();
    // queries[i] = [li, ri]
    // select subset of indices in range [li, ri] and decrement value by ATMOST 1 ie can be 0 or 1
    // Return Max no of elements that can be removed from queries while remaining gives us zero array

    // sort queries by their END index:
    sort(queries.begin(), queries.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });

    // Take a DIFFERENCE ARRAY:
    vector<vector<int>> active;
    vector<int> differenceArray(n + 2, 0);
    int count = 0;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        count += differenceArray[i];
        // collect queries that start at i:
        while (j < m && queries[j][0] == i)
        {
            active.push_back(queries[j]);
            j++;
        }
        // sort heap:
        sort(active.begin(), active.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] > b[1]; });
        while (count < nums[i])
        {
            bool valid = false;
            for (int k = 0; k < active.size(); k++)
            {
                if (active[k][1] >= i)
                {
                    count++;
                    differenceArray[active[k][1] + 1]--;
                    active.erase(active.begin() + k);
                    valid = true;
                    break;
                }
            }
            if (!valid)
            {
                break;
            }
        }
        if (count < nums[i])
        {
            return -1;
        }
    }

    return active.size(); // return no of queries that can be removed
}

int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    int m = queries.size();
    // queries[i] = [li, ri]
    // select subset of indices in range [li, ri] and decrement value by ATMOST 1 ie can be 0 or 1
    // Return Max no of elements that can be removed from queries while remaining gives us zero array

    // sort queries by their END index:
    sort(queries.begin(), queries.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });

    priority_queue<int> heap;
    vector<int> deltaArray(n + 1, 0);
    int count = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        count += deltaArray[i];
        while (j < queries.size() && queries[j][0] == i)
        {
            heap.push(queries[j][1]);
            j++;
        }
        while (count < nums[i] && !heap.empty() && heap.top() >= i)
        {
            count += 1;
            deltaArray[heap.top() + 1] -= 1;
            heap.pop();
        }
        if (count < nums[i])
        {
            return -1;
        }
    }
    return heap.size();
}

int main()
{
    vector<int> nums = {2, 0, 2};
    vector<vector<int>> queries = {{0, 2}, {0, 2}, {1, 1}};
    cout << "\nbrute_force max elem to be removed from queries= " << brute_force(nums, queries);
    cout << "\nmax elem to be removed from queries= " << maxRemoval(nums, queries);

    return 0;
}