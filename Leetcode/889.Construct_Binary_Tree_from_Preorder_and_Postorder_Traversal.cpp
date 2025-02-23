#include <bits/stdc++.h>
using namespace std;

TreeNode *recursiveBuild(vector<int> &preorder, int preStart, int preEnd, vector<int> &postorder, int postStart, int postEnd, unordered_map<int, int> &postorderMap)
{

    // if no values in preorder & postorder
    if (preStart > preEnd || postStart > postEnd)
    {
        return NULL;
    }

    // first element of preorder traversal will always be root
    TreeNode *root = new TreeNode(preorder[preStart]);

    // if only 1 node then return:
    if (preStart == preEnd)
    {
        return root;
    }
    int leftVal = preorder[preStart + 1];
    int leftIndex = postorderMap[leftVal];
    // find numbers on left of it
    int numbLeft = leftIndex - postStart + 1;

    // move left
    root->left =
        recursiveBuild(preorder, preStart + 1, preStart + numbLeft, postorder, postStart, leftIndex, postorderMap);
    // move right
    root->right =
        recursiveBuild(preorder, preStart + numbLeft + 1, preEnd, postorder, leftIndex + 1, postEnd - 1, postorderMap);

    return root;
}

TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    // reconstruct binary tree from its preorder & postorder traversals:

    // preorder: root left right
    // postorder: right left root
    // check where this node is in postorder and assign left & right halves
    // so hash all values of postorder for quick lookup
    unordered_map<int, int> postorderMap;
    for (int i = 0; i < postorder.size(); i++)
    {
        // value,index
        postorderMap[postorder[i]] = i;
    }

    // first element of preorder traversal will always be root
    TreeNode *root =
        recursiveBuild(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1, postorderMap);

    return root;
}

int main()
{
    vector<int> preorder = ;
    vector<int> postorder = ;

    return 0;
}