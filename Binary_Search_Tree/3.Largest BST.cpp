#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class NodeVal
{
public:
    // variables:
    int maxNode;
    int minNode;
    int maxSize;

    // constructor for assigning variables: (min max size)
    NodeVal(int minNode, int maxNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution
{
public:
    NodeVal helperFnc(Node *root)
    {
        if (!root)
        {
            // pass size as 0 and provide min_val=INT_MAX and max_val=INT_MIN values
            return NodeVal(INT_MAX, INT_MIN, 0);
        }

        // postorder traversal
        auto left = helperFnc(root->left);
        auto right = helperFnc(root->right);

        // check left ka max & right ka min
        if (left.maxNode < root->data && root->data < right.minNode)
        {
            // is valid bst:
            // pass new min,max,size
            return NodeVal(min(root->data, left.minNode), max(root->data, right.maxNode), (left.maxSize + right.maxSize + 1));
        }
        // if invalid bst:
        return NodeVal(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

    // time: O(n)
    int largestBst(Node *root)
    {
        // start from bottom of tree & build tree upwards
        // left<root<right for valid BST
        // postorder traversal: left right root
        // maintain (size_of_tree,max_val,min_val)
        // when checking for root to be valid: left_tree_MAX_val < root < right_tree_MIN_val
        // for INVALID BST: pass INT_MAX and INT_MIN values
        return helperFnc(root).maxSize;
    }
};