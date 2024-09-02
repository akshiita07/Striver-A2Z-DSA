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
void preorder(TreeNode *root, string path, vector<string> &traversalList)
{
    if (root == NULL)
    {
        return;
    }
    // else push new elem in list
    path += to_string(root->data);
    if (root->left == NULL && root->right == NULL)
    {
        traversalList.push_back(path);
    }
    else
    {
        path += "->";
        preorder(root->left, path, traversalList);
        preorder(root->right, path, traversalList);
    }
}

vector<string> binaryTreePaths(TreeNode *root)
{
    //  return all root-to-given node paths in any order
    vector<string> ans;
    if (root == NULL)
    {
        return ans;
    }

    // preorder traversal
    string path="";
    preorder(root, path, ans);
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
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    binaryTreePaths(root);

    return 0;
}