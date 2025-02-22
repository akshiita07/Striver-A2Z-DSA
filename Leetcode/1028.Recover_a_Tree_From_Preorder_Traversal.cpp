#include <bits/stdc++.h>
using namespace std;

TreeNode *recoverFromPreorder(string traversal)
{
    // run a preorder DFS on root of BT
    // at end node-> output D (depth) times - symbol & then value of this node  'Depth- Value'
    // depth of root node=0
    // depth of parent=D then depth of child=D+1
    // a node with only 1 child: LEFT CHILD (not right)
    // recover tree from this output traversal & return its root

    int n = traversal.length();
    stack<pair<TreeNode *, int>> stk; // stores node & its depth as a pair
    int i = 0;
    while (i < n)
    {
        // find depth:
        int depth = 0;
        while (i < n && traversal[i] == '-')
        {
            depth++;
            i++; // inc pointer
        }

        // find node value:
        int value = 0;
        while (i < n && isdigit(traversal[i]))
        {
            value = (value * 10) + (traversal[i] - '0'); // as int  //prev val in next place
            i++;                                         // inc pointer
        }

        // node creation with this value:
        TreeNode *newNode = new TreeNode(value);

        // if parent of this node exists then attach it:
        while (!stk.empty() && stk.top().second >= depth)
        {
            stk.pop(); // pop from stack to reach correct parent
        }
        if (!stk.empty())
        {
            // parent would be this top element of stack now:
            TreeNode *parent = stk.top().first;
            if (!parent->left)
            {
                parent->left = newNode;
            }
            else
            {
                parent->right = newNode;
            }
        }
        stk.push({newNode, depth}); // push this new node to stack
    }
    // if depth inc->left child
    // if depth dec/same->pop from stack to reach correct parent & give RIGHT child

    // keep on removing elements until u reach root node:
    while (stk.size() > 1)
    {
        stk.pop();
    }
    return stk.top().first; // root treenode
}

int main()
{
    string traversal = "1-2--3--4-5--6--7";

    return 0;
}