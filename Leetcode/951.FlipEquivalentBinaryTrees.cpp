#include <bits/stdc++.h>
using namespace std;

bool flipEquiv(TreeNode *root1, TreeNode *root2)
{
    // If both trees are empty, they are flip equivalent
    if (!root1 && !root2)
    {
        return true;
    }
    // If only one is empty or values are different, they are not flip equivalent
    if (!root1 || !root2 || root1->val != root2->val)
    {

        return false;
    }

    // Check if the trees are equivalent either by not flipping or by flipping
    return ((flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)));
}

int main()
{

    return 0;
}