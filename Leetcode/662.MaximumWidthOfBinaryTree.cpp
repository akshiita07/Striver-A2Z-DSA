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

int widthOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    // width of one level is defined as the length between the end-nodes

    // traversal must be LEVEL ORDER
    // make a counter on all the nodes & check  last node-first node+1 & find max out of them
    // if some nodes in between r mising then we must assign index to nodes in such a manner
    // segment trees:
    // if root node starts with 0 based indexing then left node-2*i+1 & right node=2*i+2
    // if root node starts with 1 based indexing then left node-2*i & right node=2*i+1
    // using this approach might lead to overflow so subtract min no from both nodes & then find children nodes

    queue<pair<TreeNode *, int>> qu;
    // initially push 1st node in queue using 0 based indexing
    qu.push({root, 0});
    int width = INT_MIN;
    while (!qu.empty())
    {
        int n = qu.size();
        // take current node ka index:
        int current = qu.front().second;
        // take 2 pointers to mark start & end of level
        int first;
        int last;
        for (int i = 0; i < n; i++)
        {
            // update id for any overflow
            int curId = qu.front().second - current;
            TreeNode *node = qu.front().first;
            qu.pop();
            if(i==0){
                // assign for first node
                first=curId;
            }
            if(i==n-1){
                // assign for last node
                last=curId;
            }
            if(node->left){
                // check if exists then add updated id
                qu.push({node->left, (long long)curId*2+1});
            }
            if(node->right){
                // check if exists then add updated id
                qu.push({node->right, (long long)curId*2+2});
            }
        }
        width=max(width,last-first+1);
    }
    return width;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(9);
    cout << "\nThe max width of BT1 is: " << widthOfBinaryTree(root);

    return 0;
}