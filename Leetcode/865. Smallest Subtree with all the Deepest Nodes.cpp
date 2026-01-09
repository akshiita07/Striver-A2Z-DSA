/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    pair<TreeNode*, int> findLCA(TreeNode* root) {
        if (!root) {
            // base case:
            return {nullptr, 0};
        }
        // postorder traversal (left,right,root)
        // compute depth of left & right subtree
        auto left = findLCA(root->left);
        int leftDepth = left.second;

        auto right = findLCA(root->right);
        int rightDepth = right.second;
        // if both subtrees have SAME MAXM depth-> current node is LCA
        if (leftDepth == rightDepth) {
            return {root, leftDepth + 1}; // return LCA and depth
        }
        // else go to the subtree that is deeper
        if (leftDepth > rightDepth) {
            return {left.first, leftDepth + 1}; // return LCA and depth
        } else {
            return {right.first, rightDepth + 1}; // return LCA and depth
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // return LCA of deepest leaves
        // LCA: deepest node having leaves at maxm depth
        return findLCA(root).first;
    }
};
