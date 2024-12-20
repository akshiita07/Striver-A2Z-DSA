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

void reverseOddLevelsHelper(TreeNode *left, TreeNode *right, int level)
{
    // Base case: If either node is null, return
    if (!left || !right)
    {
        return;
    }

    // If the current level is odd, swap the values of the nodes
    if (level % 2 == 1)
    {
        swap(left->val, right->val);
    }

    // Recur for the next level
    reverseOddLevelsHelper(left->left, right->right, level + 1); // Outer nodes
    reverseOddLevelsHelper(left->right, right->left, level + 1); // Inner nodes
}

TreeNode *reverseOddLevels(TreeNode *root)
{
    // reverse the node values at each odd level of the tree.
    if (!root)
    {
        return nullptr;
    }

    // Start recursive process from the children of the root
    reverseOddLevelsHelper(root->left, root->right, 1);

    return root;
}

int main()
{

    return 0;
}
