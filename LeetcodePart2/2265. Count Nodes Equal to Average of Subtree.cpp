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
class Solution {
public:
    int sizeSubtree(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int len=1; //incl root
        len+=sizeSubtree(root->left);
        len+=sizeSubtree(root->right);
        return len;
    }
    int sumSubtree(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int sum=root->val; //incl root
        sum+=sumSubtree(root->left);
        sum+=sumSubtree(root->right);
        return sum;
    }
    int averageOfSubtree(TreeNode* root) {
        // no of nodes where: node val = avg(node vals in subtree including root)
        if(root==nullptr){
            return 0;
        }
        int ans=0;
        int sizeNode=sizeSubtree(root);
        int sumNode=sumSubtree(root);
        int avgNode=sumNode/sizeNode;
        if(root->val==avgNode){
            ans++;
        }
        ans+=averageOfSubtree(root->left);
        ans+=averageOfSubtree(root->right);
        return ans;
    }
};
