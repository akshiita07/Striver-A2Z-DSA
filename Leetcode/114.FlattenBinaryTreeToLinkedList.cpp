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

// TIME: O(n)
// SPACE: O(n)->recursive stack space
void recursiveMove(TreeNode *root,TreeNode* &prev){
    // perform RIGHT LEFT ROOT recursive traversal
    if(root==NULL){
        return;
    }
    // first move to right
    recursiveMove(root->right,prev);
    // then move left
    recursiveMove(root->left,prev);
    // change right to this new node
    root->right=prev;
    // make left point as null
    root->left=NULL;
    // change prev to the current node
    prev=root;
}
void flatten(TreeNode *root)
{
    // rearrange notes in original LL where left must point to null & right points to next node
    // linked list" should be in the same order as a pre-order traversal of the binary tree
    TreeNode* prev=NULL;
    recursiveMove(root,prev);    
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right=new TreeNode(5);
    root->right->right=new TreeNode(6);
    flatten(root);
    return 0;
}