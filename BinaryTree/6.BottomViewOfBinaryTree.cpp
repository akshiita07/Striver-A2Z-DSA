#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    // constructor to initialise:
    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// TIME: O(n)
// SPACE: O(2n)->queue+map
vector<int> bottomView(TreeNode *root)
{
    vector<int> bottomView;
    if (root == NULL)
    {
        return bottomView;
    }
    // if collision then one ie more towards right is returned
    // The bottom view of the binary tree is the set of nodes visible when we see the tree from the bottom.
    // return bottom view from left to right

    // level order traversal
    queue<pair<TreeNode *, int>> qu;
    // insert 1st node in qu as a pair
    qu.push({root, 0}); // root node at vertical column 0
    // map stores node value & its vertical column
    map<int, int> hashMap;

    // each column as -2,-1,0,1,2...all last nodes will be visible
    while (!qu.empty())
    {
        // front elem in queue
        auto elem = qu.front();
        qu.pop();
        TreeNode *node = elem.first;
        int vert = elem.second;
        // check if map already contains that vertical line
        // if yes->update it
        hashMap[vert] = (node->data);

        if (node->left)
        {
            // left is 1 column before so -1
            qu.push({node->left, vert - 1});
        }
        if (node->right)
        {
            // right is 1 column after so +1
            qu.push({node->right, vert + 1});
        }
    }
    // hashMap contains all top elements
    for (auto it : hashMap)
    {
        bottomView.push_back(it.second); // node->val
    }
    cout << "\nThe bottom view from left to right is: ";
    for (auto it : bottomView)
    {
        cout << it << " ";
    }
    return bottomView;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    bottomView(root);

    return 0;
}