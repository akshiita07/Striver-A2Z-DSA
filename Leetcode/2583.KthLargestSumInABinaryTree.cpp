#include <bits/stdc++.h>
using namespace std;

// TreeNode{
// left,right,val
// }

long long kthLargestLevelSum(TreeNode *root, int k)
{
    // if no tree exists
    if (!root)
    {
        return -1;
    }
    vector<long long> levelSums;
    // to store in level order we require queue:
    queue<TreeNode *> q;
    // push root node
    q.push(root);

    // level order traversal:
    while (!q.empty())
    {
        // get size of queue
        int levelSize = q.size();
        // get current sum
        long long levelSum = 0;

        // Sum the values of the current level
        for (int i = 0; i < levelSize; i++)
        {
            // get first element
            TreeNode *node = q.front();
            // pop it from queue
            q.pop();
            // add it to sum
            levelSum += node->val;

            // move level order left->right
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        levelSums.push_back(levelSum);
    }

    if (levelSums.size() < k)
    {
        return -1;
    }
    // get kth largest level sum:
    // sort levelSums array in descending order:
    sort(levelSums.rbegin(), levelSums.rend());

    // Return the k-th largest sum
    return levelSums[k - 1];
}

int main()
{
    // root tree: 5,8,9,2,1,3,7,4,6
    int k = 2;

    return 0;
}