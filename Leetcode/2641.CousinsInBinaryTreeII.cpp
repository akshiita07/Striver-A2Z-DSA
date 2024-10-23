#include <bits/stdc++.h>
using namespace std;

TreeNode *replaceValueInTree(TreeNode *root)
{
    // replace node with sum of cousins
    // siblings: same parent NO
    // cousins: same depth & different parents

    if (!root)
    {
        // if tree does not exists:
        return nullptr;
    }

    // Queue for BFS traversal
    queue<TreeNode *> q;
    q.push(root);

    // Set the root value to 0 because it has no cousins
    root->val = 0;

    // Start BFS traversal
    while (!q.empty())
    {
        int levelSize = q.size();
        int levelSum = 0;

        // To track nodes at the current level and their sibling sums
        vector<TreeNode *> currentLevel;
        vector<int> siblingSums(levelSize, 0);

        // First, calculate the level sum
        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *node = q.front();
            q.pop();
            currentLevel.push_back(node);

            // Add the children to the queue and calculate sibling sums
            if (node->left)
            {
                q.push(node->left);
                levelSum += node->left->val;
                siblingSums[i] += node->left->val;
            }
            if (node->right)
            {
                q.push(node->right);
                levelSum += node->right->val;
                siblingSums[i] += node->right->val;
            }
        }

        // Second, update node values with cousin sums
        for (int i = 0; i < currentLevel.size(); ++i)
        {
            TreeNode *node = currentLevel[i];
            int siblingSum = siblingSums[i];       // Sum of node's siblings
            int cousinSum = levelSum - siblingSum; // Cousin sum is total level sum minus sibling sum
            if (node->left)
                node->left->val = cousinSum;
            if (node->right)
                node->right->val = cousinSum;
        }
    }

    return root;
}

int main()
{

    return 0;
}