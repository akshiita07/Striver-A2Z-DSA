#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    // constructor to initialise:
    TreeNode(int v)
    {
        data = v;
        left = nullptr;
        right = nullptr;
    }
};

// check whether a node is leaf node or not
bool isLeaf(TreeNode *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    return false;
}

void addLeftBoundary(TreeNode *root, vector<int> &boundary)
{
    // keep on going to root left
    TreeNode* temp=root->left;
    while ( temp!= NULL)
    {
        // if it is not leaf node then push
        if (!isLeaf(temp))
        {
            boundary.push_back(temp->data);
        }
        if (temp->left != NULL)
        {
            temp = temp->left;
        }
        else
        {
            // if left does NOT exist then move to right
            temp = temp->right;
        }
    }
}

void addLeafNodes(TreeNode *root, vector<int> &boundary)
{
    // for leaf node-> left & right both do not exists: INORDER TRAVERSAL-> left root right
    // or even can use preorder-> root left right
    if (isLeaf(root))
    {
        boundary.push_back(root->data);
        return;
    }
    if (root->left)
    {
        addLeafNodes(root->left, boundary);
    }
    if (root->right)
    {
        addLeafNodes(root->right, boundary);
    }
}

void addRightBoundary(TreeNode *root, vector<int> &boundary)
{
    // take stack for right boundary
    stack<int> st;
    // take right elements
    TreeNode* temp=root->right;
    while (temp != NULL)
    {
        // if it is not leaf node then push
        // if leaf node-> ie left & right both do not exists-> stop traversal
        if (!isLeaf(temp))
        {
            st.push(temp->data);
        }
        if (temp->right != NULL)
        {
            temp = temp->right;
        }
        else
        {
            // if right does not exists then move to left
            temp = temp->left;
        }
    }
    // pop elements from stack & add to ans vector
    while (!st.empty())
    {
        int elem = st.top();
        st.pop();
        boundary.push_back(elem);
    }
}

// TIME: O(n)
// SPACE: O(n)
vector<int> traverseBoundary(TreeNode *root)
{
    // traverse to boundary & leaf nodes starting from root in anti-clockwise direction

    vector<int> boundary;
    if (root == NULL)
    {
        // if no root present-> empty ans
        return {};
    }
    // push root in ans if it is not a leaf node
    if (!isLeaf(root))
    {
        boundary.push_back(root->data);
    }

    // left boundary without leaves
    addLeftBoundary(root, boundary);

    // leaf nodes
    addLeafNodes(root, boundary);

    // right boundary in reverse order without leaves
    addRightBoundary(root, boundary);

    return boundary;
}

int main()
{
    TreeNode *root1 = new TreeNode(10);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(20);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(8);
    root1->left->right->left = new TreeNode(7);
    root1->right->left = new TreeNode(18);
    root1->right->right = new TreeNode(25);
    cout << "\nThe boundary traversal of nodes in root1 is ";
    vector<int> ans1 = traverseBoundary(root1);
    for (auto it : ans1)
    {
        cout << it << " ";
    }
    // ans:  10 5 3 7 18 25 20

    return 0;
}