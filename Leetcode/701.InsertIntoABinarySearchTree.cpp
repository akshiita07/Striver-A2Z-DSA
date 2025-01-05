#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node *left;
    node *right;

    // constructor to initialise:
    node(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

node *insertIntoBST(node *root, int val)
{
    if (root == NULL)
    {
        node *root = new node(val);
        return root;
    }
    // new val must be inserted at <= ie ceil ke left pe
    node *ceil = root;
    while (1)
    {
        if (ceil->val > val)
        {
            if (ceil->left != NULL)
            {
                ceil = ceil->left;
            }
            else
            {
                ceil->left = new node(val);
                break;
            }
        }
        else if (ceil->val <= val)
        {
            if (ceil->right != NULL)
            {
                ceil = ceil->right;
            }
            else
            {
                ceil->right = new node(val);
                break;
            }
        }
    }
    return root;
}

int main()
{
    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(7);
    root->left->left = new node(1);
    root->left->right = new node(3);
    int val_to_insert = 5;
    insertIntoBST(root, val_to_insert);

    return 0;
}