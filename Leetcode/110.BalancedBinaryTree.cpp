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

// TIME: O(n)
int heightOfBinTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lHeight = heightOfBinTree(root->left);
    int rHeight = heightOfBinTree(root->right);
    // check if difference of left & right height exceeds 1
    if (lHeight == -1 || rHeight == -1)
    {
        return -1;
    }
    if (abs(lHeight - rHeight) > 1)
    {
        // false
        return -1;
    }
    return 1 + max(lHeight, rHeight);
}

// TIME: O(n)->single traversal
// SPACE: O(n)->only for recursive stack space at worst for skew tree it is n
bool isBalanced(TreeNode *root)
{
    // height(left)-height(right)<=1
    if (heightOfBinTree(root) == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    // example1:
    // TreeNode *root = new TreeNode(3);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);
    // cout << "\nIs eg1 tree balanced?: " << isBalanced(root);

    // example2:
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(3);
    root->left->left->left=new TreeNode(4);
    root->left->left->right=new TreeNode(4);
    cout<<"\nIs eg2 tree balanced?: "<<isBalanced(root);

    return 0;
}