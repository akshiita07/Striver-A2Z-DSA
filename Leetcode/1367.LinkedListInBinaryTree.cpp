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

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int data1)
    {
        val = data1;
        next = nullptr;
    }

    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

ListNode *convertArrToLL(int arr[], int n)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *mover = head;
    for (int i = 1; i < n; i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traverse(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

bool dfs(ListNode *head, TreeNode *root)
{
    // check if LL is null
    if (head == nullptr)
    {
        // we have reached end of LL so return true
        return true;
    }
    // check if tree root is null
    if (root == nullptr)
    {
        return false;
    }

    // if current value of root matches LL then checkfor left & rigth tree:
    if (head->val == root->val)
    {
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }
    // else return false when heads value does not matches with root value:
    return false;
}

// TIME: O(n*m)
// SPACE: O()
bool isSubPath(ListNode *head, TreeNode *root)
{
    // check for all linked list elements:
    // recursively check if the current node of the tree matches the current node of the linked list
    if (root == NULL)
    {
        return false;
    }
    // does current node matches node of LL
    if (dfs(head, root) == true)
    {
        return true;
    }

    // check for left & right tree:
    return ((isSubPath(head, root->left)) || (isSubPath(head, root->right)));
}

int main()
{
    int arr[] = {4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode *node = convertArrToLL(arr, n);
    cout << "\nTraversing LL: ";
    traverse(node);

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(8);
    root->right->left->right->left = new TreeNode(1);
    root->right->left->right->right = new TreeNode(3);

    cout << "\nDoes LL contains in this tree: " << isSubPath(node, root);

    return 0;
}