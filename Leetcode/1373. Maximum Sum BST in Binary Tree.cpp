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

class NodeVal
{
public:
    // variables:
    int maxNode;
    int minNode;
    int maxSum;

    // constructor for assigning variables: (min max size)
    NodeVal(int minNode, int maxNode, int maxSum)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSum = maxSum;
    }
};

class Solution
{
public:
    NodeVal helperFnc(TreeNode *root, int &maxSum)
    {
        if (!root)
        {
            // pass size as 0 and provide min_val=INT_MAX and max_val=INT_MIN values
            return NodeVal(INT_MAX, INT_MIN, 0);
        }

        // postorder traversal
        auto left = helperFnc(root->left, maxSum);
        auto right = helperFnc(root->right, maxSum);

        // check left ka max & right ka min
        if (left.maxNode < root->val && root->val < right.minNode)
        {
            // is valid bst:
            // pass new min,max,size
            int currSum = (left.maxSum + right.maxSum + root->val);
            maxSum = max(maxSum, currSum);
            return NodeVal(min(root->val, left.minNode), max(root->val, right.maxNode), currSum);
        }
        // if invalid bst:
        return NodeVal(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));
    }

    // time: O(n)
    int maxSumBST(TreeNode *root)
    {
        // start from bottom of tree & build tree upwards
        // left<root<right for valid BST
        // postorder traversal: left right root
        // maintain (size_of_tree,max_val,min_val)
        // when checking for root to be valid: left_tree_MAX_val < root < right_tree_MIN_val
        // for INVALID BST: pass INT_MAX and INT_MIN values
        int maxSum = 0;
        helperFnc(root, maxSum);
        return maxSum;
    }
};