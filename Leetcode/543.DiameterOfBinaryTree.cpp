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

int findHeight(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = findHeight(root->left);
    int r = findHeight(root->right);
    return 1 + max(l, r);
}

// TIME: O(n^2)->finding height+ moving to next node
// SPACE: O()
int bruteforce(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    // length of the longest path between any two nodes in a tree
    //  The length of a path between two nodes is represented by the number of edges between them.

    int maxi = INT_MIN;
    // go find height of left + height of right->maxm
    int lHeight = findHeight(root->left);
    cout << "\nMaxm height for left subtree is: " << lHeight;
    int rHeight = findHeight(root->right);
    cout << "\nMaxm height for right subtree is: " << rHeight;
    int l = bruteforce(root->left);
    int r = bruteforce(root->right);
    maxi = max(max(l, r), (lHeight + rHeight));
    return maxi;
}

int heightTree(TreeNode *root,int dia)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = heightTree(root->left,dia);
    int r = heightTree(root->right,dia);
    dia=max(dia,l+r);
    return 1 + max(l, r);
}

int diameterOfBinaryTree(TreeNode *root){
    int dia=0;
    return heightTree(root,dia);    
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    // cout << "\nThe length of diameter of tree is: " << bruteforce(root);
    cout << "\nThe length of diameter of tree is: " << diameterOfBinaryTree(root);

    return 0;
}