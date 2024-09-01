#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // constructor to initialise:
    TreeNode(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

// level order traversal: complexity: time:O(n) space:O(n)
// recursive traversal: complexity: time:O(n) space:O(height of tree)
// so use recursive order soln:
void preorder(TreeNode *root, int level,vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    // if that level is first time then only add value
    if (ans.size() == level)
    {
        // ie coming to first node of this level
        cout << root->val<<" ";
        ans.push_back(root->val);
    }
    // left
    preorder(root->left, level + 1,ans);
    // right
    preorder(root->right, level + 1,ans);
}
vector<int> leftView(TreeNode *root)
{
    // traverse from left to right & get all 1st nodes--> preorder
    // preorder: root left right
    vector<int> ans;
    preorder(root, 0,ans);
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->right->right = new TreeNode(4);
    leftView(root);

    return 0;
}