#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<vector<int>> &grid, int x)
{
    // m*n grid:
    int m = grid.size();
    int n = grid[0].size();
    // 1operation: add x to or subtract x from any element in the grid
    // uni-value grid = grid where all the elements of it are equal

    // 0. Convert grid to 1d array:
    vector<int> nums;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            nums.push_back(grid[i][j]);
        }
    }
    // 1. if all elements do NOT have same remainder on dividing by x then impossible so return -1
    int remainder = nums[0] % x;
    int size = nums.size();
    for (int i = 1; i < size; i++)
    {
        if (nums[i] % x != remainder)
        {
            return -1;
        }
    }
    // 2. Sort the elements & take out median element
    sort(nums.begin(), nums.end());
    int median = nums[size / 2];
    // 3. For MIN operations, convert all elements to median element by + or - x
    int operations = 0;
    for (int i = 0; i < size; i++)
    {
        // no of operations to convert element to medan element is (nums[i]-median)/x
        operations += abs(nums[i] - median) / x;
    }
    return operations;
}

int main()
{
    vector<vector<int>> grid = {{2, 4}, {6, 8}};
    int x = 2;
    cout << "\nMinimum operations to make a uni-value grid: " << minOperations(grid, x);

    return 0;
}