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

// ceil: find lowest value>=key     : first greatest element
//  time: O(log2n)
int ceil_of_binary_search_tree(node *root, int key)
{
    int ceil = INT_MIN;
    // possible greater elements: change ceil
    while (root != NULL)
    {
        if (root->val == key)
        {
            ceil = root->val;
            return ceil; // found exact match
        }
        if (root->val > key)
        {
            ceil = root->val;
            root = root->left;
        }
        else if (root->val < key)
        {
            root = root->right;
        }
    }
    return ceil;
}

// floor: find greatest value<=key  :first smallest element
int floor_of_binary_search_tree(node *root, int key)
{
    int floor = INT_MAX;
    while (root != NULL)
    {
        if (root->val == key)
        {
            floor = root->val;
            return floor;
        }
        if (root->val > key)
        {
            root = root->left;
        }
        else
        {
            floor = root->val;
            root = root->right;
        }
    }
    return floor;
}

int main()
{
    node *root = new node(10);
    root->left = new node(5);
    root->right = new node(13);
    root->left->left = new node(3);
    root->left->right = new node(6);
    root->left->left->left = new node(2);
    root->left->left->right = new node(4);
    root->left->right->right = new node(9);
    root->right->left = new node(11);
    root->right->right = new node(14);
    cout << "\nCeil of 8 is: " << ceil_of_binary_search_tree(root, 8);
    cout << "\nFloor of 7 is: " << floor_of_binary_search_tree(root, 7);

    return 0;
}