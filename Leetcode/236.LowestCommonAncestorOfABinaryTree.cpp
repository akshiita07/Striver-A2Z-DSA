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
// SPACE: O(n)
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // traverse tree
    if(root==NULL || root==p || root==q){
        return root;
    }
    // if node==p or node==q then return that specific node else return null
    TreeNode* l=lowestCommonAncestor(root->left,p,q);
    TreeNode* r=lowestCommonAncestor(root->right,p,q);
    // if a node has both p & q under it then it is the LCA
    // while returning:
    if(l==NULL){
        return r;
    }else if(r==NULL){
        return l;
    }else{
        return root;
    }
}

int main()
{
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(5);
    root->left->left=new TreeNode(6);
    root->left->right=new TreeNode(2);
    root->left->right->left=new TreeNode(7);
    root->left->right->right=new TreeNode(4);
    root->right=new TreeNode(1);
    root->right->left=new TreeNode(0);
    root->right->right=new TreeNode(8);
    cout<<"\nFor 5,1 lca= ";
    TreeNode* ans1=lowestCommonAncestor(root,root->left,root->right);
    cout<<ans1->data;
    cout<<"\nFor 5,4 lca= ";
    TreeNode* ans2=lowestCommonAncestor(root,root->left,root->left->right->right);
    cout<<ans2->data;
    

    return 0;
}