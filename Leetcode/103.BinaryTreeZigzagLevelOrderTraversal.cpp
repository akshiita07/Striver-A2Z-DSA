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

// TIME: O(n)->almost like level order traversal
// SPACE: O(n)
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> zigzag;
    //   from left to right, then right to left for the next level and alternate between

    if (root == NULL)
    {
        return zigzag;
    }

    // maintain a queue:
    queue<TreeNode *> qu;
    // push root node in queue
    qu.push(root);

    // flag variable to note whether v r traversing from LtoR or from RtoL
    bool leftToRight = true; // true for LtoR & false for RtoL

    // TRAVERSE UNTIL QUEUE GETS EMPTY
    while (!qu.empty())
    {
        int n = qu.size();
        // take ans ke liye vector
        vector<int> row(n);
        for (int i = 0; i < n; i++)
        {
            // remove elem from queue
            TreeNode *elem = qu.front();
            qu.pop();

            // add them to row but first check flag!!
            int index;
            if (leftToRight == true)
            {
                // insert normally
                index = i;
            }
            else
            {
                // insert from backwards
                index = n - i - 1;
            }
            row[index] = elem->val;

            // if left of elem exists then push in queue
            if (elem->left != NULL)
            {
                qu.push(elem->left);
            }
            // if right of elem exists then push in queue
            if (elem->right != NULL)
            {
                qu.push(elem->right);
            }
        }

        // inverse flag
        leftToRight = !leftToRight;
        // push our row:
        zigzag.push_back(row);
    }

    return zigzag;
}

int main()
{
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->right = new TreeNode(6);
    cout << "\nThe zig-zag traversal of nodes in root1 is ";
    vector<vector<int>> ans1 = zigzagLevelOrder(root1);
    for (auto row : ans1)
    {
        cout << "[ ";
        for (auto it : row)
        {
            cout << it << " ";
        }
        cout << "]";
    }

    TreeNode *root2 = new TreeNode(3);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);
    cout << "\nThe zig-zag traversal of nodes in root2 is ";
    vector<vector<int>> ans2 = zigzagLevelOrder(root2);
    for (auto row : ans2)
    {
        cout << "[ ";
        for (auto it : row)
        {
            cout << it << " ";
        }
        cout << "]";
    }

    return 0;
}