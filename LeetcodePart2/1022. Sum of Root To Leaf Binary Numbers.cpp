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
    int convertBinToDec(string bin){
        // int n=bin.length();
        // int dec=0;
        // for(int i=0;i<n;i++){
        //     dec+=(bin[i]-'0')+(dec*2);
        // }
        // return dec;
        //or:
        return stoi(bin,nullptr,2);
    }

    void dfs(TreeNode* root, string path, int &ans){
        if(!root) return;
        path += (root->val + '0');

        if(!root->left && !root->right){
            ans += convertBinToDec(path);
            return;
        }

        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }

    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        dfs(root, "", ans);
        return ans;
    }
};
