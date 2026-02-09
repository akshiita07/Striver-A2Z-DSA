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
    vector<int> arr;

    void findInorder(TreeNode* root) {
        if (!root) {
            return;
        }
        // left node right
        findInorder(root->left);
        arr.push_back(root->val);
        findInorder(root->right);
    }

    TreeNode* buildBalancedTree(int l,int r){
        if(l>r){
            return nullptr;
        }
        int mid=(l+r)/2;
        TreeNode* root=new TreeNode(arr[mid]);
        root->left=buildBalancedTree(l,mid-1);
        root->right=buildBalancedTree(mid+1,r);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        // depth of left & right subtree difference <=1
        findInorder(root);
        return buildBalancedTree(0,arr.size()-1);
    }
};
