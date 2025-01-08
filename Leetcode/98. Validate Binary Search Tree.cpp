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
class Solution
{
public:
    // time: O(n)
    // space: O(1)
    bool checkValid(TreeNode *root, long minVal, long maxVal)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->val >= maxVal || root->val <= minVal)
        {
            return false;
        }
        return checkValid(root->left, minVal, root->val) && checkValid(root->right, root->val, maxVal);
    }
    bool isValidBST(TreeNode *root)
    {
        // left<node<right
        // assign a range of permissible values to each node
        // start with [-INT_MIN,INT_MAX]
        // left<root ie  [-INT_MIN,root_val]
        // right>root ie  [root_val,INT_MAX]]
        return checkValid(root, LONG_MIN, LONG_MAX);
    }
};