#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    TreeNode *first; // first violation
    TreeNode *prev;
    TreeNode *middle; // first ke next wala violation
    TreeNode *last;   // last violation
public:
    void inorderTraversal(TreeNode *root)
    {
        // left root right
        if (root == NULL)
        {
            return;
        }
        inorderTraversal(root->left);
        // check:
        if (prev != NULL && (root->val < prev->val))
        {
            // violation:
            if (first == NULL)
            {
                // ie it is first violation
                first = prev;
                middle = root;
            }
            else
            {
                // second violation:
                last = root;
            }
        }
        // move prev:
        prev = root;
        inorderTraversal(root->right);
    }

    // time: O(n):traversal + O(nlogn):sorting + O(n) = O(2n+nlogn)
    // space :O(n):storing traversals
    void brute_force(TreeNode *root)
    {
        // in bst 2 nodes are swapped so recover it?
        // inorder traversal
        // sort inorder to get CORRECT inorder (left root right)
        // check both traversals to see which nodes are swapped
    }

    // time: O(n):traversal
    // space: O(1):without any recursive stack space
    void recoverTree(TreeNode *root)
    {
        // in bst 2 nodes are swapped so recover it?
        // incorrect inorder (left root right) traversal: compute which 2 nodes are swapped
        // if next root is NOT GREATER to the previous element then d prev element is a violation
        // if 2 violations found-> swap both (first & last) violations
        // if only 1 violation found-> swap ADJACENT (first & middle)  violations
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN); // first elem for inorder traversal
        inorderTraversal(root);

        // now we have violations:
        if (first && last)
        {
            swap(first->val, last->val);
        }
        else if (first && middle)
        {
            swap(first->val, middle->val);
        }
    }
};