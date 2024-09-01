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

bool isMirror(TreeNode *l, TreeNode *r)
{
    if (l == NULL && r == NULL)
    {
        // both r null
        return true;
    }
    if (l == NULL || r == NULL)
    {
        // ony one is null
        return false;
    }

    return ((l->data == r->data) && (isMirror(l->left, r->right)) && (isMirror(l->right, r->left)));
}

// TIME: O(n)
// SPACE: O(1)
bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
    {
        // nothing inside so symmetric
        return true;
    }
    // check whether it is a mirror of itself (i.e., symmetric around its center)

    // for mirrored version-> left & right is interchanged
    // ie root->left==root->right
    // ie perform preorder on left subtree & reverse preorder on right subtree & ans must be same
    if (isMirror(root->left, root->right))
    {
        return true;
    }
    return false;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    cout << "\nIs tree1 symmetric about its center: " << isSymmetric(root);

    cout << endl;

    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->right = new TreeNode(3);
    root1->right->right = new TreeNode(3);
    cout << "\nIs tree2 symmetric about its center: " << isSymmetric(root1);

    return 0;
}