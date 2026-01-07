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
    // total dfs:
    long long dfsTotal(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return root->val + dfsTotal(root->left) + dfsTotal(root->right);
    }

    // dfs of subtrees n max product:
    long long maxProd=0;
    long long dfs(TreeNode* root, int totalSum) {
        if (!root) {
            return 0;
        }
        long long currentSum =
            root->val + dfs(root->left, totalSum) + dfs(root->right, totalSum);
        long long product = currentSum * (totalSum - currentSum);
        maxProd = max(maxProd, product);
        return currentSum;
    }

    const int MOD = 1e9 + 7;
    int maxProduct(TreeNode* root) {
        // find total sum:
        long long totalSum = dfsTotal(root);
        // to find max product:
        dfs(root, totalSum);
        return maxProd % MOD;
    }
};
