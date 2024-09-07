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

TreeNode *recursiveBuild(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &inorderMap)
// Passing inorderMap by reference avoids copying it during recursive calls, reducing overhead
{
    // if no values in preorder & inorder
    if (postStart > postEnd || inStart > inEnd)
    {
        return NULL;
    }

    // last element of POSTORDER traversal will always be root
    TreeNode *root = new TreeNode(postorder[postEnd]);

    // find where does this node lie in inorder using hash map:
    int inorderPosition = inorderMap[root->data];
    // find numbers on left of it
    int numbOnLeft = inorderPosition - inStart;

    // move left: remove postorder se root ie last element
    root->left = recursiveBuild(postorder, postStart , postStart +numbOnLeft-1, inorder, inStart, inorderPosition - 1, inorderMap);
    // move right
    root->right = recursiveBuild(postorder, postStart+numbOnLeft, postEnd-1, inorder, inorderPosition + 1, inEnd, inorderMap);

    return root;
}

// recursive soln
TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder)
{
    //  Given two integer arrays postorder and inorder, construct and return the binary tree.
    // inorder: left root right
    // postorder: left right root

    // now check where this node is in inorder and assign left & right halves
    // so hash all values of inorder for quick lookup
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); i++)
    {
        // value,index
        inorderMap[inorder[i]] = i;
    }

    int postorderSize=postorder.size();
    // LAST element of POSTORDER traversal will always be root
    TreeNode *root = recursiveBuild(postorder, 0, postorderSize - 1, inorder, 0, inorder.size() - 1, inorderMap);

    return root;
}

int main()
{
    vector<int> postorder = {9,15,7,20,3};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *treeCreated = buildTree(postorder, inorder);
    return 0;
}