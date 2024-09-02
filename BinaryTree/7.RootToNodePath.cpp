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

// TIME: O(n)->preorder loop
// SPACE: O(n)->recursive stack space
bool preorder(TreeNode *root,TreeNode *node,vector<string>& traversalList){
    if(root==NULL){
        // ie neither of left or right found given node
        // so go back & pop last element that u added in list
        return false;
    }
    // else push new elem in list
    traversalList.push_back(to_string(root->data));
    if(root->data==node->data){
        return true;
        // give ans back
    }
    // if they return true & good:
    if(preorder(root->left,node,traversalList) || preorder(root->right,node,traversalList)){
        return true;
    }
    // else pop last element
    traversalList.pop_back();
    return false;
}

vector<string> binaryTreePaths(TreeNode *root,TreeNode *node)
{
    //  return all root-to-given node paths in any order
    vector<string> ans;
    if(root==NULL){
        return ans;
    }
    // preorder traversal
    preorder(root,node,ans);
    // traverse & if currentNode!=node then add in list of traversal
    cout << "\nAll the paths from root to leaf of tree are: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(3);
    binaryTreePaths(root,root->left->right->right);     //ie give path from root node to 7th node

    return 0;
}