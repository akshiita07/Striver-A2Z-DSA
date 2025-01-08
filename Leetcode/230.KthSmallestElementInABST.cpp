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
    vector<int> inorder(TreeNode *root){
        vector<int> ans;
        if(root==NULL){
            return {};
        }
        vector<int> leftArr=inorder(root->left);
        ans.insert(ans.end(),leftArr.begin(),leftArr.end());
        ans.push_back(root->val);
        vector<int> rightArr=inorder(root->right);
        ans.insert(ans.end(),rightArr.begin(),rightArr.end());
        return ans;
    }
    // time: O(n):traversal+O(nlogn):sorting
    // space: O(n):to store traveral in some array
    int brute_force(TreeNode *root, int k)
    {
        // traverse bst
        // add traversal elements to array
        vector<int> elem=inorder(root);     //inorder is always in sorted order
        // sort array
        sort(elem.begin(),elem.end());
        // find kth smallest element
        return elem[k-1];
    }
    // time: O(n):traversal
    // space: O(n):to store traveral in some array
    int better(TreeNode *root, int k)
    {
        vector<int> elem=inorder(root);
        return elem[k-1];
    }
};
// to find kth LARGEST: N-KTH SMALLEST