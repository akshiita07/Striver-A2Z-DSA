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

// TIME: O(n)->traversal
// SPACE: O(height of binary tree) -> for complete tree height of BT= logn where n:no of nodes in BT
void brute_force(TreeNode *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    count++;
    brute_force(root->left, count);
    brute_force(root->right, count);
}

int findLeftHeight (TreeNode *root){
    int height=0;
    while(root!=NULL){
        height++;
        root=root->left;
    }
    return height;
}
int findRightHeight (TreeNode *root){
    int height=0;
    while(root!=NULL){
        height++;
        root=root->right;
    }
    return height;
}

// TIME: O(logn)^2  height of tree is always O(logn) & not traversing all nodes at max logn nodes
// SPACE: O(logn)->recursive stack space
int countNodes(TreeNode *root)
{
    //  return the number of the nodes in complete tree-> all nodes in the last level are as far left as possible.
    // It can have between 1 and 2^h nodes inclusive at the last level h
    if (root == NULL)
    {
        return 0;
    }
    // check for every subtree what is height of tree then calculate
    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);

    // if complete tree then left height=right height then no of nodes=2^height-1
    if (lh == rh)
    {
        return pow(2,lh)-1;
    }
    else
    {
        // if left height != right height then traverse in both left & right
        return countNodes(root->left)+countNodes(root->right)+1; //(add 1 for current node)
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    int count = 0;
    brute_force(root, count);
    cout << "\nBRUTE->The number of nodes in this complete binary tree are: " << count;
    cout<<"\nThe number of nodes in this complete binary tree are: "<<countNodes(root);

    return 0;
}