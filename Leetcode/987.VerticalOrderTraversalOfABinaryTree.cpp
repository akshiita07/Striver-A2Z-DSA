#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // constructor to initialise:
    TreeNode(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

// TIME: O(n)
// SPACE: O(log(n))->for multiset->+O(n)->for vertical for storing node +O(n)->for queue
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> verticalOrder;
    if(root==NULL){
        return verticalOrder;
    }
    //  list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column
    // for overlapping nodes in same column-> add them in SORTED order

    // (vertical column, level no) pair
    // root at (0,0)
    // vertical columns like -2,-1,0,1,2
    // levels like 0,1,2,3

    // using level order
    queue<pair<TreeNode *, pair<int, int>>> qu;

    // (vertical),( every (level) multiple (nodes))
    // use multiset for storing same values if present
    map<int, map<int, multiset<int>>> nodes;

    // add root in queue
    qu.push({root, {0, 0}}); // vertical:0 level:0
    // when moving to left child: vertical column moves by -1
    // when moving to right child: vertical column moves by +1
    // when moving to a child, level inc by +1
    while (!qu.empty())
    {
        // take front element of queue
        auto elem = qu.front();
        // pop ir:
        qu.pop();
        // extract node out of elem
        TreeNode *node = elem.first;
        // extract vertical colm:
        int vert = elem.second.first;
        // extract level:
        int lev = elem.second.second;
        // insert node in map ds
        nodes[vert][lev].insert(node->val);
        // check if left exists
        if (node->left)
        {
            qu.push({node->left, {vert - 1, lev + 1}});
        }
        // check if right exists
        if (node->right)
        {
            qu.push({node->right, {vert + 1, lev + 1}});
        }
    }

    // traverse thru map
    for (auto i : nodes)
    {
        vector<int> colm;
        for (auto j : i.second)
        {
            colm.insert(colm.end(), j.second.begin(), j.second.end());
        }
        verticalOrder.push_back(colm);
    }

    cout << "\nThe vertical traversal gives: ";
    for (auto row : verticalOrder)
    {
        cout << "[";
        for (auto it : row)
        {
            cout << it << " ";
        }
        cout << "]";
    }

    return verticalOrder;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    verticalTraversal(root);

    return 0;
}