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

// time:O(1)
// space:O(height of tree)
class BSTIterator
{
public:
    // inorder traversal: left root right
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        st.push(root); // root node
        while (root->left != NULL)
        {
            root = root->left;
            st.push(root);
        }
    }

    int next()
    {
        // Moves the pointer to the right, then returns the number at the pointer.
        TreeNode *node = st.top();
        st.pop(); // remove this element
        TreeNode *curr = node;
        if (curr->right != NULL)
        {
            curr = curr->right;
            st.push(curr);
            while (curr->left != NULL)
            {
                curr = curr->left;
                st.push(curr);
            }
        }
        return node->val;
    }

    bool hasNext()
    {
        // Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false
        if (st.empty())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */