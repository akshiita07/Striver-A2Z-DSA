#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// time:O(n*n): n nodes & for every ode determine left right & stuff
TreeNode *insert(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return new TreeNode(val);
    }
    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

TreeNode *brute_force(vector<int> &preorder)
{
    TreeNode *root = NULL;
    for (auto it : preorder)
    {
        root = insert(root, it);
    }
    return root;
}

// time: O(nlogn):sorting + O(n):to create bst from preorder & inorder
// space: O(n):to store inorder tree
TreeNode *constructFromPreIn(vector<int> &preorder, vector<int> &inorder, int &i, int inStart, int inEnd, unordered_map<int, int> &inMap)
{
    if (inStart > inEnd)
    {
        return nullptr;
    }

    int rootVal = preorder[i++];
    TreeNode *root = new TreeNode(rootVal);

    int inIndex = inMap[rootVal];

    root->left = constructFromPreIn(preorder, inorder, i, inStart, inIndex - 1, inMap);
    root->right = constructFromPreIn(preorder, inorder, i, inIndex + 1, inEnd, inMap);

    return root;
}

TreeNode *better(vector<int> &preorder)
{
    // inorder traversal is always sorted
    // unique bst from preorder & inorder:
    // preorder: root left right
    // inorder: left root right
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());

    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++)
    {
        inMap[inorder[i]] = i;
    }

    int i = 0;
    return constructFromPreIn(preorder, inorder, i, 0, inorder.size() - 1, inMap);
}

// time: O(3*n)=O(n) :worst time is visiting a node 3 times
TreeNode *buildTree(vector<int> &preorder, int &i, int upper_bound)
{
    // if no more elemnets to be inserted in bst OR if exceeded bound:
    if (i == preorder.size() || preorder[i] > upper_bound)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(preorder[i++]);
    root->left = buildTree(preorder, i, root->val);
    root->right = buildTree(preorder, i, upper_bound);
    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    // preorder: root left right
    // each node belongs within range ..start from [INT_MIN,INT_MAX] for left node range: [INT_MIN,root_val] and  for right node range: [root_val,INT_MAX]
    // only upper bound reqd (lower bound not reqd)

    // pointer:
    int i = 0;
    return buildTree(preorder, i, INT_MAX);
}