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

vector<int> largestValues(TreeNode *root)
{
    //  return an array of the largest value in each row of the tree
    // har ek row ki largest value ko array me push karna hai
    vector<int> ans;
    if (!root)
    {
        return ans;
    }
    // dfs traversal:
    queue<TreeNode *> qu;
    // add root node:
    qu.push(root);
    // traverse:
    while (!qu.empty())
    {
        int maxVal = INT_MIN;
        int level = qu.size();

        for (int i = 0; i < level; i++)
        {
            // take out:
            TreeNode *node = qu.front();
            qu.pop();
            maxVal = max(maxVal, node->val);
            if (node->left)
            {
                qu.push(node->left);
            }
            if (node->right)
            {
                qu.push(node->right);
            }
        }
        ans.push_back(maxVal);
    }

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    vector<int> ans = largestValues(root);
    cout << "Largest values in each row of the binary tree: \n";
    for (int it : ans)
    {
        cout << it << " ";
    }

    return 0;
}