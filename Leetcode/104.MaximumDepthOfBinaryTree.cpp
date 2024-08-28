#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    node *left;
    node *right;

    // constructor to initialise:
    node(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

int maxDepth(TreeNode *root)
{
    if(root==NULL){
        // height is 0
        return 0;
    }
    int leftHeight=maxDepth(root->left);
    int rightHeight=maxDepth(root->right);
    return 1+max(leftHeight,rightHeight);
}

int main()
{

    return 0;
}