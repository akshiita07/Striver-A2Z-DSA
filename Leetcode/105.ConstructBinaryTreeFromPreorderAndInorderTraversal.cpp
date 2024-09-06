#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    // constructor to initialise:
    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode *recursiveBuild(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &inorderMap)
// Passing inorderMap by reference avoids copying it during recursive calls, reducing overhead
{

    // if no values in preorder & inorder
    if (preStart > preEnd || inStart > inEnd)
    {
        return NULL;
    }

    // first element of preorder traversal will always be root
    TreeNode *root = new TreeNode(preorder[preStart]);

    // find where does this node lie in inorder using hash map:
    int inorderPosition = inorderMap[root->data];
    // find numbers on left of it
    int numbOnLeft = inorderPosition - inStart;

    // move left
    root->left = recursiveBuild(preorder, preStart + 1, preStart + numbOnLeft, inorder, inStart, inorderPosition - 1, inorderMap);
    // move right
    root->right = recursiveBuild(preorder, preStart + numbOnLeft + 1, preEnd, inorder, inorderPosition + 1, inEnd, inorderMap);

    return root;
}

// recursive soln
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    //  Given two integer arrays preorder and inorder, construct and return the binary tree.
    // inorder: left root right
    // PREorder: root left right

    // now check where this node is in inorder and assign left & right halves
    // so hash all values of inorder for quick lookup
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); i++)
    {
        // value,index
        inorderMap[inorder[i]] = i;
    }

    // first element of preorder traversal will always be root
    TreeNode *root = recursiveBuild(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);

    return root;
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *treeCreated = buildTree(preorder, inorder);
    return 0;
}