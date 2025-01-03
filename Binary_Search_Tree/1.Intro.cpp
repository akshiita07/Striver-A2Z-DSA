#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    // constructor to initialise:
    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// left<root<right

// time: height of tree: O(log2n)
node *search(node *root, int key)
{
    while (root != null && root->data != key)
    {
        if (root->data > key)
        {
            return search(root->left, key);
        }
        else
        {
            return search(root->right, key);
        }
    }
    return root;
}

bool isValidBSTInorder(vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] <= arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int main()
{
    node *root = new node(8);
    root->left = new node(5);
    root->right = new node(12);
    root->left->left = new node(4);
    root->left->right = new node(7);
    root->left->right->left = new node(6);
    root->right->left = new node(10);
    root->right->right = new node(14);
    root->right->right->left = new node(13);
    searchNode(10);

    return 0;
}