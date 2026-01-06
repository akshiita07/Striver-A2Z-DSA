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
    int maxLevelSum(TreeNode* root) {
        // Create queue:
        queue<TreeNode*> qu;
        // push root:
        qu.push(root);
        int level = 1;
        int maxLevel = 1;
        int maxSum = INT_MIN;

        // loop while queue not empty:
        while (!qu.empty()) {
            int size = qu.size();
            int sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = qu.front();
                qu.pop();
                sum += node->val;

                if (node->left) {
                    qu.push(node->left);
                }
                if (node->right) {
                    qu.push(node->right);
                }
            }

            if (maxSum < sum) {
                maxSum = sum;
                maxLevel = level;
            }
            level++;
        }
        return maxLevel;
    }
};
