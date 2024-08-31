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
vector<int> getTopView(TreeNode *root)
{
    vector<int> topView;
    if (root == NULL)
    {
        return topView;
    }
    // The Top view of the binary tree is the set of nodes visible when we see the tree from the top.
    // return top view from left to right
    // each new column will have a top node ie visible

    // level order traversal
    queue<pair<TreeNode *, int>> qu;
    // insert 1st node in qu as a pair
    qu.push({root, 0}); // root node at vertical column 0
    // map stores node value & its vertical column
    map<int, int> hashMap;

    // each column as -2,-1,0,1,2...all first nodes will be visible
    while (!qu.empty())
    {
        // front elem in queue
        auto elem = qu.front();
        qu.pop();
        TreeNode *node = elem.first;
        int vert = elem.second;
        // check if map already contains that vertical line
        // if not exists then add
        if (hashMap.find(vert) == hashMap.end())
        {
            hashMap[vert] = (node->data);
        }
        // else do not add

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
        topView.push_back(it.second); // node->val
    }
    cout << "\nThe top view from left to right is: ";
    for (auto it : topView)
    {
        cout << it << " ";
    }
    return topView;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->right = new TreeNode(7);
    root->left->left->right->left = new TreeNode(9);
    root->left->left->right->left->left = new TreeNode(10);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(8);
    root->right->right->left->right = new TreeNode(11);
    getTopView(root);

    return 0;
}