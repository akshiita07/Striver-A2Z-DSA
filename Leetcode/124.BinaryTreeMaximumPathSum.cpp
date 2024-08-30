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

int findHeight(TreeNode* root,int& maxi){
    if(root==NULL){
        return 0;
    }
    int l=findHeight(root->left,maxi);
    int r=findHeight(root->right,maxi);
    // if l/r gives negative ans then do not consider them instead take it as 0
    if(l<0){
        l=0;
    }
    if(r<0){
        r=0;
    }
    maxi=max(maxi,root->val+l+r);
    return root->val+max(l,r);
}

int maxPathSum(TreeNode *root)
{
    int ans=INT_MIN;
    findHeight(root,ans);
    return ans;
}

int main()
{
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    cout << "\nThe maxm path sum of nodes in root1= " << maxPathSum(root1);

    TreeNode *root2 = new TreeNode(-10);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);
    cout << "\nThe maxm path sum of nodes in root2= " << maxPathSum(root2);

    return 0;
}