#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

int countMinSwaps(vector<int> &arr)
{
    int n = arr.size();
    vector<pair<int, int>> indexedArr;
    for (int i = 0; i < n; i++)
    {
        indexedArr.emplace_back(arr[i], i);
    }

    // Sort by value to determine target positions
    sort(indexedArr.begin(), indexedArr.end());

    // Mark visited elements
    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; i++)
    {
        // If the element is already in the correct position or visited, skip it
        if (visited[i] || indexedArr[i].second == i){
            continue;
        }

        // Calculate the size of the cycle
        int cycleLength = 0;
        int j = i;

        while (!visited[j])
        {
            visited[j] = true;
            j = indexedArr[j].second; // Move to the next index in the cycle
            cycleLength++;
        }

        // Add (cycleLength - 1) swaps for this cycle
        if (cycleLength > 1)
        {
            swaps += (cycleLength - 1);
        }
    }

    return swaps;
}

int minimumOperations(TreeNode *root)
{
    if (!root){
        return 0;
    }

    queue<TreeNode *> q;
    q.push(root);
    int ans = 0;

    // Level order traversal
    while (!q.empty())
    {
        int n = q.size();
        vector<int> levelValues;

        // Collect values at the current level
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            levelValues.push_back(node->val);
            if (node->left){
                q.push(node->left);
            }
            if (node->right){
                q.push(node->right);
            }
        }

        // Count minimum swaps to sort this level
        ans += countMinSwaps(levelValues);
    }

    return ans;
}

int main()
{

    return 0;
}