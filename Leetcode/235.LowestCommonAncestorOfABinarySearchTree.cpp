#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    // time: O(log2n) and space:O(1)
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // the FIRST INTERSECTION POINT from the given nodes to the root of tree
        if (root == NULL)
        {
            return NULL;
        }
        // find value of root
        int current = root->val;
        // if both nodes lie on right
        if (current < p->val && current < q->val)
        {
            // move to right:
            return lowestCommonAncestor(root->right, p, q);
        }
        // if both nodes lie on left
        if (current > p->val && current > q->val)
        {
            // move to left:
            return lowestCommonAncestor(root->left, p, q);
        }
        // cannot determine:
        return root;
    }
};