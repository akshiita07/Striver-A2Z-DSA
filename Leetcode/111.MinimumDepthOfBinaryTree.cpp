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

int minDepth(TreeNode *root)
{
    if(root==NULL){
        // height is 0
        return 0;
    }
    if(root->left==NULL){
        return 1+minDepth(root->right);
    }
    if(root->right==NULL){
        return 1+minDepth(root->left);
    }
    int leftHeight=minDepth(root->left);
    int rightHeight=minDepth(root->right);
    return 1+min(leftHeight,rightHeight);
}

int main()
{
    TreeNode* root= new TreeNode(3);
    root->left= new TreeNode(9);
    root->right= new TreeNode(20);
    root->right->left= new TreeNode(15);
    root->right->right= new TreeNode(7);
    cout<<"\nThe min depth is: "<<minDepth(root);

    return 0;
}