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
public:
    // time: O(n):convert to inorder +O(n):2 pointer
    // sace:O(n):to store inorder
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }
        // left root right
        vector<int> ans;
        vector<int> leftSide = inorderTraversal(root->left);
        ans.insert(ans.end(), leftSide.begin(), leftSide.end());
        ans.push_back(root->val);
        vector<int> rightSide = inorderTraversal(root->right);
        ans.insert(ans.end(), rightSide.begin(), rightSide.end());
        return ans;
    }
    bool brute_force(TreeNode *root, int k)
    {
        // does there exists 2 different nodes whose sum of values=k
        vector<int> inorder = inorderTraversal(root);
        // apply 2 sum:
        int i = 0;
        int j = inorder.size() - 1;

        while (i < j)
        {
            if ((inorder[i] + inorder[j]) == k)
            {
                return true;
            }
            else if ((inorder[i] + inorder[j]) > k)
            {
                // greater so move j
                j = j - 1;
            }
            else
            {
                i = i + 1;
            }
        }
        return false;
    }

    bool findTarget(TreeNode *root, int k)
    {
        // does there exists 2 different nodes whose sum of values=k
        // using BST iterator solve
    }
};