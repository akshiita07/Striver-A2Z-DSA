#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // constructor to initialise:
    TreeNode(int d)
    {
        val = d;
        left = nullptr;
        right = nullptr;
    }
};

// root left right

// are tree 1 and tree2 identical??
bool isSameTree(TreeNode *p, TreeNode *q)
{
    // traverse the tree & check any 1 traversal of both trees must be same
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if (p == NULL || q == NULL)
    {
        return false;
    }
    if ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
    {
        return true;
    }
    return false;
}

int main()
{
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    cout << "\nIs tree1 and tree2 same: " << isSameTree(root1, root2);

    TreeNode *root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);

    cout << "\nIs tree1 and tree3 same: " << isSameTree(root1, root3);

    return 0;
}