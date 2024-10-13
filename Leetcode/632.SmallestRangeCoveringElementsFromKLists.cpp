#include <bits/stdc++.h>
using namespace std;

vector<int> smallestRange(vector<vector<int>> &nums)
{
    // Min-heap to store {element, list index, element index}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

    int maxVal = INT_MIN;         // To track the maximum value in the current range
    int start = 0, end = INT_MAX; // To store the best range

    // Initialize the heap with the first element of each list
    for (int i = 0; i < nums.size(); ++i)
    {
        minHeap.push({nums[i][0], i, 0}); // {value, list index, element index}
        maxVal = max(maxVal, nums[i][0]); // Track the maximum of the first elements
    }

    // Process the heap
    while (!minHeap.empty())
    {
        auto curr = minHeap.top();
        minHeap.pop();

        int minVal = curr[0];  // Current minimum value
        int listIdx = curr[1]; // Which list this value came from
        int elemIdx = curr[2]; // Index of the element in that list

        // Check if this range is smaller
        if (maxVal - minVal < end - start)
        {
            start = minVal;
            end = maxVal;
        }

        // If there are more elements in the current list, push the next one to the heap
        if (elemIdx + 1 < nums[listIdx].size())
        {
            int nextVal = nums[listIdx][elemIdx + 1];
            minHeap.push({nextVal, listIdx, elemIdx + 1});
            maxVal = max(maxVal, nextVal); // Update the maxVal
        }
        else
        {
            // If we reached the end of one of the lists, we cannot form a complete range
            break;
        }
    }

    return {start, end};
}

int main()
{
    vector<vector<int>> nums = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    cout << "\nSmallest range cntg all nos: ";
    vector<int> ans = smallestRange(nums);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}