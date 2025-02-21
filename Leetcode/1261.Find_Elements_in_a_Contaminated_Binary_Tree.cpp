#include <bits/stdc++.h>
using namespace std;

// Given a binary tree st root.val=0 and For any treeNode:
// treeNode.val= x and treeNode.left != null, => treeNode.left.val == 2 * x + 1
// treeNode.val= x and treeNode.right != null =>  treeNode.right.val == 2 * x + 2
// CONTAMINATED BT: all treeNode.val=  -1

class FindElements
{
public:
    unordered_set<int> recoveredValues; // for O(1) lookup
    void recover(TreeNode *node, int value)
    {
        // recovering dfs:
        if (node == NULL)
        {
            return;
        }
        node->val = value;
        recoveredValues.insert(value);
        recover(node->left, 2 * value + 1);
        recover(node->right, 2 * value + 2);
    }
    FindElements(TreeNode *root)
    {
        // Initializes  object with contaminated BT then recovers it
        if (root != NULL)
        {
            recover(root, 0);
        }
    }

    bool find(int target)
    {
        // return true if target value exists in the recovered BT
        if (recoveredValues.find(target) != recoveredValues.end())
        {
            return true; // found
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    return 0;
}